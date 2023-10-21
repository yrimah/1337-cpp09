#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cmath>
# include <vector>

typedef std::vector<int> intVec;
typedef std::vector<int>::iterator intVecIterators;
typedef std::vector<std::pair<int, int> > vecPairs;
typedef std::vector<std::pair<int, int> >::iterator Iterators;

int checkValidArgs(char **argv);

#endif