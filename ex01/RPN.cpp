#include "RPN.hpp"

int verifyRpn(std::string rpn_exp)
{
    int i = 0;

    if (!rpn_exp[i])
        return (1);
    while (rpn_exp[i])
    {
        if (rpn_exp[i] == '+' || rpn_exp[i] == '-' || rpn_exp[i] == '/'
            || rpn_exp[i] == '*' || rpn_exp[i] == ' ' || isdigit(rpn_exp[i]))
            {
                if (isdigit(rpn_exp[i]) && isdigit(rpn_exp[i + 1]))
                    return (1);
                else
                    i++;
            }
        else
            return (1);
    }
    return (0);
}

int rpnCalculator(std::string _exp, bool *error)
{
    *error = false;
    std::stack<int> _numbers;
    size_t pos = 0;
    while (pos < _exp.size())
    {
        if (isdigit(_exp[pos]))
        {
            char* end;
            int num = std::strtol(_exp.c_str() + pos, &end, 10);
            if (end == _exp.c_str() + pos)
            {
                *error = true;
                return (1);
            }
            _numbers.push(num);
            pos = end - _exp.c_str();
        }
        else if (_exp[pos] == ' ')
            pos++;
        else
        {
            if (_numbers.size() < 2)
            {
                *error = true;
                return (1);
            }
            int num1 = _numbers.top();
            _numbers.pop();
            int num2 = _numbers.top();
            _numbers.pop();

            int result;
            switch (_exp[pos])
            {
                case '+':
                    result = num2 + num1;
                    break;
                case '-':
                    result = num2 - num1;
                    break;
                case '*':
                    result = num2 * num1;
                    break;
                case '/':
                    if (num1 == 0)
                    {
                        *error = true;
                        return (1);
                    }
                    result = num2 / num1;
                    break;
                default:
                    *error = true;
                    return (1);
            }
            _numbers.push(result);
            pos++;
        }
    }
    if (_numbers.size() == 1)
        return (_numbers.top());
    *error = true;
    return (1);
}
