#include "RPN.hpp"

int main(int argc, char *argv[]){
    if (argc == 2){
        try{
            RPN input(argv[1]);
            std::cout << input.doMath() << std::endl;
        } catch (const std::exception &e){
            std::cout << e.what() << std::endl;
            return (1);
        }
    } else {
        std::cerr << "Input Error: Wrong Argument Count.\nUsage: ./RPN <input with quotes>" << std::endl;
        return (1);
    }
    return (0);
}