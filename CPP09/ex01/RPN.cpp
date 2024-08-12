#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(std::string &str){
    if (_str.empty())
        throw std::invalid_argument("No input. Usage: ./RPN <input with quotes>");
}