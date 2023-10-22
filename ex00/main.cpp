#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        // parsing database //
        std::fstream database_file;

        database_file.open("data.csv", std::ios::in);
        if (!database_file.is_open())
        {
            std::cout << "Error: could not open file." << std::endl;
            return (1);
        }
        std::map<std::string, std::string> _database;
        std::string tmp;
        std::string buff_1;
        std::string buff_2;

        std::getline(database_file, tmp);
        while (std::getline(database_file, tmp, ','))
        {
            buff_1 = tmp;
            while (std::getline(database_file, tmp))
            {
                buff_2 = tmp;
                break;
            }
            _database.insert(std::pair<std::string, std::string>(buff_1, buff_2));
        }
        database_file.close();

        // parsing input  && apply calculation //
        std::fstream _inputfile;

        _inputfile.open(argv[1], std::fstream::in);
        if (!_inputfile.is_open())
        {
            std::cout << "Error: could not open file." << std::endl;
            return (1);
        }

        std::string _tmp;
        std::string _buff_1;
        std::string _buff_2;
        std::string _date = "";
        std::string _datebase = "";

        _inputfile >> _tmp;
        if (_tmp.find("date") == std::string::npos)
        {
            std::cout << "Error: Invalid input file" << std::endl;
            _inputfile.close();
            return (1);
        } 
        std::getline(_inputfile, _tmp);
        while (std::getline(_inputfile, _tmp))
        {
            _tmp.erase(std::remove(_tmp.begin(), _tmp.end(), '"'), _tmp.end());
            _tmp.erase(std::remove_if(_tmp.begin(), _tmp.end(), ::isspace), _tmp.end());

            std::istringstream _stream_tmp(_tmp);
            if (_tmp.find('|') != std::string::npos)
            {
                std::getline(_stream_tmp, _buff_1, '|');
                if (valid_date(_buff_1, &_date) && _buff_1 != "")
                {
                    if (valid_date(_buff_1, &_date) == 2)
                        std::cout << "Error: Minimum database date passed => " << _buff_1 << std::endl;
                    else if (valid_date(_buff_1, &_date) == 3)
                        std::cout << "Error: not a date => " << _buff_1 << std::endl;
                    else if (valid_date(_buff_1, &_date) == 4)
                        std::cout << "Error: Maximum database date passed => " << _buff_1 << std::endl;
                    else
                        std::cout << "Error: bad input => " << _buff_1 << std::endl;
                    continue;
                }
                std::getline(_stream_tmp, _buff_2);
                if (_buff_1 == "")
                {
                    std::cout << "Error: bad input => | " << _buff_2 << std::endl;
                    continue;
                }
                if ((_buff_2 == ""))
                {
                    std::cout << "Error: bad syntax near | => " << _buff_1 << std::endl;
                    continue;
                }
                bool isdig = true;
                
                for (size_t i = 0; _buff_2[i]; i++)
                {
                    if (!isdigit(_buff_2[i]) && _buff_2[i] != '.')
                        isdig = false;
                }
                if (atof(_buff_2.c_str()) < 0)
                {
                    std::cout << "Error: not a positive number." << std::endl;
                    continue;
                }
                if (!isdig)
                {
                    std::cout << "Error: not a number." << std::endl;
                    continue;
                }
                if (atof(_buff_2.c_str()) > 1000)
                {
                    std::cout << "Error: too large a number." << std::endl;
                    continue;
                }
                std::map<std::string, std::string>::iterator _i;
                std::map<std::string, std::string>::iterator _i2;

                int _fdate = atoi(_date.c_str());

                for (_i = _database.begin(); _i != _database.end(); _i++)
                {
                    valid_date(_i->first, &_datebase);
                    if (_fdate == atoi(_datebase.c_str()))
                    {
                        std::cout << _buff_1 << " => " << _buff_2 << " = " << (atof(_i->second.c_str()) * atof(_buff_2.c_str())) << std::endl;
                        break;
                    }
                }
                while (_fdate != atoi(_datebase.c_str()))
                {
                    _fdate--;
                    for (_i2 = _database.begin(); _i2 != _database.end(); _i2++)
                    {
                        valid_date(_i2->first, &_datebase);
                        if (_fdate == atoi(_datebase.c_str()))
                        {
                            std::cout << _buff_1 << " => " << _buff_2 << " = " << (atof(_i2->second.c_str()) * atof(_buff_2.c_str())) << std::endl;
                            break;
                        }
                    }
                    if (_fdate == atoi(_datebase.c_str()))
                        break;
                }
            }
            else
            {
                std::getline(_stream_tmp, _buff_1);
                std::cout << "Error: bad input => " << _buff_1 << std::endl;
            }
        }
        _inputfile.close();
        return (0);
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
}
