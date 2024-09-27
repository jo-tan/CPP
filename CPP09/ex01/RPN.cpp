/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:11:36 by jo-tan            #+#    #+#             */
/*   Updated: 2024/09/20 13:31:21 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const std::string &str): _str(str) {
    if (_str.empty())
        throw std::invalid_argument("Input Error: No input.\nUsage: ./RPN <input with quotes>");
    parsing(_str);
}

RPN::RPN(const RPN &cpy){
    *this = cpy;
}

RPN &RPN::operator=(const RPN &cpy){
    if (this != &cpy){
        _str = cpy._str;
        _input = cpy._input;
    }
    return *this;
}

void RPN::parsing(const std::string _str){
    std::string number;
    for (size_t i = 0; i < _str.size(); ++i){
        char ch = _str[i];
        if (ch >= '0' && ch <= '9') {
            number += ch;
        } else if (ch == ' ' && !number.empty()){
            _input.push(number);
            number.clear();
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if (!number.empty()){
                _input.push(number);
                number.clear();
            }
            std::string op(1, ch);
            _input.push(op);
        } else if (ch != ' '){
            std::string badToken;
            badToken = ch;
            throw std::runtime_error("Invalid character in input: " + badToken);
        }
    }
    if (!number.empty()){
        _input.push(number);
    }
}

void RPN::AddOverflow(int a, int b){
    if ((b > 0 && a > std::numeric_limits<int>::max() - b) || 
    (b < 0 && a < std::numeric_limits<int>::min() - b)){
        throw std::runtime_error("Integer overflow (Add)");
    }
}

void RPN::SubOverflow(int a, int b){
    if ((b > 0 && a < std::numeric_limits<int>::max() + b) || 
    (b < 0 && a > std::numeric_limits<int>::min() + b)){
        throw std::runtime_error("Integer overflow (Sub)");
    }
}

void RPN::MulOverflow(int a, int b){
    if (a > 0 && (b > std::numeric_limits<int>::max() / a || b < std::numeric_limits<int>::min() / a)){
        throw std::runtime_error("Integer overflow (Mul)");
    }
    else if (a < 0 && (b < std::numeric_limits<int>::max() / a || b > std::numeric_limits<int>::min() / a)){
        throw std::runtime_error("Integer overflow (Mul)");
    }
}

int RPN::doMath(){
    std::stack<int> stack;
    std::queue<std::string> input = _input;

    while (!input.empty()){
        std::string token = input.front();
        input.pop();

        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')){
            if (stack.size() < 2){
                throw std::runtime_error("Invalid RPN expression");
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = 0;

            switch (token[0]){
                case '+':
                    AddOverflow(a, b);
                    result = a + b;
                    break;
                case '-':
                    SubOverflow(a, b);
                    result = a - b;
                    break;
                case '*':
                    MulOverflow(a, b);
                    result = a * b;
                    break;
                case '/':
                    if (b == 0){
                        throw std::runtime_error("Division by zero");
                    }
                    result = a / b;
                    break;
                default:
                    throw std::runtime_error("Invalid Operator");
            }

            stack.push(result);
            // std::cout << "RESULT: " << result << std::endl;
        } else {
            long int number = std::stol(token.c_str());
            if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
                throw std::runtime_error("Integer Overflow: " + token);
            stack.push(number);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Invalid RPN expression");
    
    return stack.top();
}
