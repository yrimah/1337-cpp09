#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (checkValidArgs(argv))
        {
            std::cout << "Error" << std::endl;
            return (1);
        }

        vecPairs _pairs;
        int left = -1;

        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
        std::cout << std::endl;

        size_t i = 1;
        while ((int)i < argc)
        {
            if (argv[i] && argv[i + 1])
            {
                _pairs.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
            }
            else if (argv[i] && !argv[i + 1])
                left = atoi(argv[i]);
            i += 2;
        }

        Iterators _i;
        intVec _lower;
        intVec _higher;

        for (_i = _pairs.begin(); _i != _pairs.end(); _i++)
        {
            if (_i->first > _i->second)
            {
                if (_higher.size() < 1)
                    _higher.push_back(_i->first);
                else if (_higher.size() == 1)
                {
                    if (_i->first > _higher.back())
                        _higher.push_back(_i->first);
                    else
                    {
                        int tmp = _higher.back();
                        _higher.pop_back();
                        _higher.push_back(_i->first);
                        _higher.push_back(tmp);
                    }
                }
                else
                {
                    int after = INT_MAX;
                    intVecIterators ToStore;
                    bool end = false;
                    // intVecIterators i1;

                    for (intVecIterators i1 = _higher.begin(); i1 != _higher.end(); i1++)
                    {
                        // if (_i->first == *i1)
                        //     continue;
                        if (after > (_i->first - *i1))
                        {
                            i1++;
                            // i1++;
                            if (++i1 == _higher.end())
                            {
                                std::cout << "enter\n";
                                end = true;
                            }
                            else
                            {
                                end = false;
                                ToStore = i1;
                                after = _i->first - *i1;
                            }
                            // i1--;
                            // i1--;
                            i1--;
                        }
                        // if (i1 == _higher.end())
                        //     break;
                    }
                    std::cout << after << " || \n";// << *ToStore << " || " << std::endl;
                    if (end)
                        _higher.push_back(_i->first);
                    else
                        // ToStore--;
                        _higher.insert(ToStore, _i->first);
                    // std::cout << after << " || " << *ToStore << " ::end" << std::endl;
                    // std::cout << after << "\n";
                }
            }
            else
            {
                // _lower.push_back(_i->first);
                // _higher.push_back(_i->second);
                if (_higher.size() < 1)
                    _higher.push_back(_i->second);
                else if (_higher.size() == 1)
                {
                    if (_i->second > _higher.back())
                        _higher.push_back(_i->second);
                    else
                    {
                        int tmp = _higher.back();
                        _higher.pop_back();
                        _higher.push_back(_i->second);
                        _higher.push_back(tmp);
                    }
                }
                else
                {
                    int after = INT_MAX;
                    intVecIterators ToStore;
                    bool end = false;
                    // intVecIterators i1;

                    for (intVecIterators i1 = _higher.begin(); i1 != _higher.end(); i1++)
                    {
                        // if (_i->first == *i1)
                        //     continue;
                        if (after > (_i->second - *i1))
                        {
                            i1++;
                            // i1++;
                            if (++i1 == _higher.end())
                            {
                                std::cout << "enter\n";
                                end = true;
                            }
                            else
                            {
                                end = false;
                                ToStore = i1;
                                after = _i->second - *i1;
                            }
                            // i1--;
                            // i1--;
                            i1--;
                        }
                        // if (i1 == _higher.end())
                        //     break;
                    }
                    // std::cout << after << " || \n";// << *ToStore << " || " << std::endl;
                    if (end)
                        _higher.push_back(_i->second);
                    else
                        // ToStore--;
                        _higher.insert(ToStore, _i->second);
                    // std::cout << after << " || " << *ToStore << " ::end" << std::endl;
                    // std::cout << after << "\n";
                }
            }
        }
        std::cout << "\nOriginal Part:\n" << std::endl;
        for (_i = _pairs.begin(); _i != _pairs.end(); _i++)
            std::cout << _i->first << " || " << _i->second << std::endl;
        
        // std::cout << std::endl << "Lowest Part:\n\n";

        // intVecIterators i1;
        intVecIterators i2;
        // for (i1 = _lower.begin(); i1 != _lower.end(); i1++)
        //     std::cout << *i1 << std::endl;

        std::cout << std::endl << "Highest Part:\n\n";
        
        for (i2 = _higher.begin(); i2 != _higher.end(); i2++)
            std::cout << *i2 << std::endl;
        // // if (left != -1)
        //     // std::cout << left << " || " << std::endl;
    }
    else
    {
        std::cout << "Program requires arguments." << std::endl;
        return (1);
    }
}