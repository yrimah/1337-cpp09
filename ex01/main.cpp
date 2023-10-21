#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        bool error = false;
        std::string _exp;

        _exp = argv[1];
        if (verifyRpn(_exp))
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        rpnCalculator(_exp, &error);
        if (error)
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        std::cout << rpnCalculator(_exp, &error) << std::endl;
        return (0);
    }
    else
    {
	    std::cout << "Error" << std::endl;
	    return (1);
    }
}
