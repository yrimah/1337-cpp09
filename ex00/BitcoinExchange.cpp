#include "BitcoinExchange.hpp"

int verify(std::string toVerify)
{
    for (size_t i = 0; toVerify[i]; i++)
    {
        if (!isdigit(toVerify[i]))
            return (1);
    }
    return (0);
}

int valid_date(std::string date, std::string *_setdate)
{
    std::string part;

    *_setdate = "";
    std::istringstream _stream_input(date);
    std::getline(_stream_input, part, '-');
    *_setdate += part;
    if (verify(part))
        return(3);
    int _year = atoi(part.c_str());
    std::getline(_stream_input, part, '-');
    *_setdate += part;
    if (verify(part))
        return(3);
    int month = atoi(part.c_str());
    std::getline(_stream_input, part, '-');
    *_setdate += part;
    if (verify(part))
        return(3);
    int day = atoi(part.c_str());

    if (_year < 2009)
        return (2);
    if (_year == 2009 && month < 2 && day < 2)
        return (2);
    if ( _year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return (1);
    if (_year > 2022 || (_year == 2022 && (month > 3))
        || (_year == 2022 && (month == 3) && day > 29))
        return (4);
    return (0);
}