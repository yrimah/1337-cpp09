#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>

int verifyRpn(std::string rpn_exp);
int rpnCalculator(std::string _exp, bool *error);

#endif