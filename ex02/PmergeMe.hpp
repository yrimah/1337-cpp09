#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cmath>
# include <vector>
# include <deque>

typedef std::vector<int> intVec;
typedef std::vector<int>::iterator intVecIterators;
typedef std::vector<std::pair<int, int> > vecPairs;
typedef std::vector<std::pair<int, int> >::iterator Iterators;

typedef std::deque<int> intDeq;
typedef std::deque<int>::iterator intDeqIterators;
typedef std::deque<std::pair<int, int> > deqPairs;
typedef std::deque<std::pair<int, int> >::iterator DeqIterators;

int checkValidArgs(char **argv);
int checkDuplicates(char **argv);

#endif