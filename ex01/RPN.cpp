#include <iostream>
#include <stack>
#include <algorithm>

int valid_exp(std::string exp)
{
    int i = 0;
    if (!exp[i])
        return (1);
    while (exp[i])
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/'
            || exp[i] == '*' || exp[i] == ' '
            || (exp[i] >= '0' && exp[i] <= '9'))
            {
                if ((exp[i] >= '0' && exp[i] <= '9')
                    && (exp[i + 1] >= '0' && exp[i + 1] <= '9'))
                    return (1);
                else
                    i++;
            }
        else
            return (1);
    }
    return (0);
}

int claculateRPN(std::string _exp, int *_status)
{
    *_status = 0;
    std::stack<int> _opr;
    size_t pos = 0;
    while (pos < _exp.size())
    {
        if (isdigit(_exp[pos]))
        {
            char* end;
            int num = std::strtol(_exp.c_str() + pos, &end, 10);
            if (end == _exp.c_str() + pos)
            {
                // Failed to convert
                *_status = 1;
                return (1);
            }
            _opr.push(num);
            pos = end - _exp.c_str();
        }
        else if (_exp[pos] == ' ')
        {
            // Skip spaces
            pos++;
        }
        else
        {
            // Operator
            if (_opr.size() < 2)
            {
                *_status = 1;
                return (1);
            }
            int operand2 = _opr.top();
            _opr.pop();
            int operand1 = _opr.top();
            _opr.pop();

            int result;
            switch (_exp[pos])
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    // std::cout << result << "DEBUG" << std::endl;
                    break;
                case '/':
                    if (operand2 == 0)
                    {
                        *_status = 1;
                        return (1); // Division by zero
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    *_status = 1;
                    return (1); // Invalid operator
            }
            // std::cout << result << "DEBUG" << std::endl;
            _opr.push(result);
            pos++;
        }
    }
    if (_opr.size() == 1)
        return (_opr.top());
    *_status = 1;
    return (1);
}
