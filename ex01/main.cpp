#include <iostream>

int claculateRPN(std::string _exp, int *_status);
int valid_exp(std::string exp);

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int _status = 0;
        std::string _exp;

        _exp = argv[1];
        if (valid_exp(_exp))
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        claculateRPN(_exp, &_status);
        if (_status)
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        std::cout << claculateRPN(_exp, &_status) << std::endl;
        return (0);
    }
    else
    {
	    std::cout << "Error" << std::endl;
	    return (1);
    }
}
