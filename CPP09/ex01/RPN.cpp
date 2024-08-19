#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(std::string &str){
    if (_str.empty())
        throw std::invalid_argument("No input. Usage: ./RPN <input with quotes>");
}

int RPN::doMath(std::queue<int> _input){
    int res = q[0];
    int next = q[1];
    int sign = q[2];
}