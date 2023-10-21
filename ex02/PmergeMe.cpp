#include "PmergeMe.hpp"

int checkValidArgs(char **argv)
{
    for (size_t i = 1; argv[i]; i++)
    {
        for (size_t j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
                return (1);
        }
    }
    return (0);
}