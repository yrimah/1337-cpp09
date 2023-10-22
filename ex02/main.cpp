#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (checkValidArgs(argv))// || checkDuplicates(argv))
        {
            std::cout << "Error" << std::endl;
            return (1);
        }

        // Vector container //

        vecPairs _pairs;
        int left = -1;

        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << std::endl;

        clock_t startVec, endVec;
        startVec = clock();


        size_t i = 1;
        while ((int)i < argc)
        {
            if (argv[i] && argv[i + 1])
            {
                if (atoi(argv[i]) <= atoi(argv[i + 1]))
                    _pairs.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
                else
                    _pairs.push_back(std::make_pair(atoi(argv[i + 1]), atoi(argv[i])));
            }
            else if (argv[i] && !argv[i + 1])
                left = atoi(argv[i]);
            i += 2;
        }

        Iterators _i;
        intVec _lower;
        intVec _higher;
        int element = 0;

        for (_i = _pairs.begin(); _i != _pairs.end(); _i++)
        {
            if (_i->first >= _i->second)
                element = _i->first;
            else
                element = _i->second;

            if (_higher.size() < 1)
                _higher.push_back(element);
            else if (_higher.size() == 1)
            {
                if (element > _higher.back())
                    _higher.push_back(element);
                else
                {
                    int tmp = _higher.back();
                    _higher.pop_back();
                    _higher.push_back(element);
                    _higher.push_back(tmp);
                }
            }
            else
            {
                intVecIterators ToStore;
                intVecIterators i1;

                int nearest = _higher.back();
                int minDifference = std::abs(element - nearest);
                for (i1 = _higher.begin(); i1 != _higher.end(); i1++)
                {
                    int difference = std::abs(element - *i1);

                    if (difference <= minDifference)
                    {
                        ToStore = i1;
                        nearest = *i1;
                        if (element < nearest)
                            ToStore--;
                        minDifference = difference;
                    }
                }
                if (++ToStore == _higher.end())
                    _higher.push_back(element);
                else
                    _higher.insert(ToStore, element);
            }
        }

        for (Iterators it = _pairs.begin(); it != _pairs.end(); it++)
        {
            if (it->first == _higher.front() || it->second == _higher.front())
                _higher.insert(_higher.begin(), it->first);
        }

        intVecIterators i2;
        for (i2 = _higher.begin(); i2 != _higher.end(); i2++)
        {
            for (Iterators it = _pairs.begin(); it != _pairs.end(); it++)
            {
                if (it->first == _higher.front())
                    continue;
                if (it->second == *i2)
                    _lower.push_back(it->first);
            }
        }

        intVecIterators bounds_it;
        for (intVecIterators it = _lower.begin(); it != _lower.end(); it++)
        {
            bounds_it = std::upper_bound(_higher.begin(), _higher.end(), *it);
            if (bounds_it != _higher.end())
                _higher.insert(bounds_it, *it);
            else
                _higher.push_back(*it);
        }

        if (left != -1)
        {
            intVecIterators leftToBound = std::upper_bound(_higher.begin(), _higher.end(), left);
            if (leftToBound != _higher.end())
                _higher.insert(leftToBound, left);
            else
                _higher.push_back(left);
        }
        endVec = clock();
        double timeTakenByVec = double(endVec - startVec) / double(CLOCKS_PER_SEC);
        // End vector //

        // Deque container //

        deqPairs _deqPairs;
        int leftDeq = -1;

        // std::cout << "Before: ";
        // for (int i = 1; i < argc; i++)
        //     std::cout << argv[i] << " ";
        // std::cout << std::endl;

        clock_t startDeq, endDeq;
        startDeq = clock();


        size_t j = 1;
        while ((int)j < argc)
        {
            if (argv[j] && argv[j + 1])
            {
                if (atoi(argv[j]) <= atoi(argv[j + 1]))
                    _deqPairs.push_back(std::make_pair(atoi(argv[j]), atoi(argv[j + 1])));
                else
                    _deqPairs.push_back(std::make_pair(atoi(argv[j + 1]), atoi(argv[j])));
            }
            else if (argv[j] && !argv[j + 1])
                leftDeq = atoi(argv[j]);
            j += 2;
        }

        DeqIterators _iDeq;
        intDeq _lowerDeq;
        intDeq _higherDeq;
        int elementDeq = 0;

        for (_iDeq = _deqPairs.begin(); _iDeq != _deqPairs.end(); _iDeq++)
        {
            if (_iDeq->first >= _iDeq->second)
                elementDeq = _iDeq->first;
            else
                elementDeq = _iDeq->second;

            if (_higherDeq.size() < 1)
                _higherDeq.push_back(elementDeq);
            else if (_higherDeq.size() == 1)
            {
                if (elementDeq > _higherDeq.back())
                    _higherDeq.push_back(elementDeq);
                else
                {
                    int tmpDeq = _higherDeq.back();
                    _higherDeq.pop_back();
                    _higherDeq.push_back(elementDeq);
                    _higherDeq.push_back(tmpDeq);
                }
            }
            else
            {
                intDeqIterators ToStoreDeq;
                intDeqIterators i1Deq;

                int nearestDeq = _higherDeq.back();
                int minDifferenceDeq = std::abs(elementDeq - nearestDeq);
                for (i1Deq = _higherDeq.begin(); i1Deq != _higherDeq.end(); i1Deq++)
                {
                    int differenceDeq = std::abs(elementDeq - *i1Deq);

                    if (differenceDeq <= minDifferenceDeq)
                    {
                        ToStoreDeq = i1Deq;
                        nearestDeq = *i1Deq;
                        if (elementDeq < nearestDeq)
                            ToStoreDeq--;
                        minDifferenceDeq = differenceDeq;
                    }
                }
                if (++ToStoreDeq == _higherDeq.end())
                    _higherDeq.push_back(elementDeq);
                else
                    _higherDeq.insert(ToStoreDeq, elementDeq);
            }
        }

        for (DeqIterators it = _deqPairs.begin(); it != _deqPairs.end(); it++)
        {
            if (it->first == _higherDeq.front() || it->second == _higherDeq.front())
                _higherDeq.insert(_higherDeq.begin(), it->first);
        }

        intDeqIterators i2Deq;
        for (i2Deq = _higherDeq.begin(); i2Deq != _higherDeq.end(); i2Deq++)
        {
            for (DeqIterators it = _deqPairs.begin(); it != _deqPairs.end(); it++)
            {
                if (it->first == _higherDeq.front())
                    continue;
                if (it->second == *i2Deq)
                    _lowerDeq.push_back(it->first);
            }
        }

        intDeqIterators bounds_itDeq;
        for (intDeqIterators it = _lowerDeq.begin(); it != _lowerDeq.end(); it++)
        {
            bounds_itDeq = std::upper_bound(_higherDeq.begin(), _higherDeq.end(), *it);
            if (bounds_itDeq != _higherDeq.end())
                _higherDeq.insert(bounds_itDeq, *it);
            else
                _higherDeq.push_back(*it);
        }

        if (leftDeq != -1)
        {
            intDeqIterators leftToBoundDeq = std::upper_bound(_higherDeq.begin(), _higherDeq.end(), leftDeq);
            if (leftToBoundDeq != _higherDeq.end())
                _higherDeq.insert(leftToBoundDeq, leftDeq);
            else
                _higherDeq.push_back(leftDeq);
        }
        endDeq = clock();
        double timeTakenByDeq = double(endDeq - startDeq) / double(CLOCKS_PER_SEC); 
        // // End deque //

        std::cout << "After: ";
        for (i2 = _higher.begin(); i2 != _higher.end(); i2++)
            std::cout << *i2 << " ";
        std::cout << std::endl;

        // std::cout << "After: ";
        // for (i2Deq = _higherDeq.begin(); i2Deq != _higherDeq.end(); i2Deq++)
        //     std::cout << *i2Deq << " ";
        // std::cout << std::endl;

        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << timeTakenByVec << " sec" << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::fixed << timeTakenByDeq << " sec" << std::endl;
    }
    else
    {
        std::cout << "Program requires arguments." << std::endl;
        return (1);
    }
}