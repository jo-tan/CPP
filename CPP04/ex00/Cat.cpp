#include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << GREY << "Class Cat: Default Constructor" << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal()
{
    *this = copy;
    std::cout << GREY << "Class Cat: Copy Constructor" << RESET << std::endl;
}

Cat::~Cat()
{
    std::cout << GREY << "Class Cat: Deconstructor" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    std::cout << GREY << "Class Cat: Assignation Operator" << RESET << std::endl;
    if (this == &obj)
        return *this;
    this->_type = obj._type;
    return *this;
}

void    Cat::makeSound()const
{
    std::cout << YELLOW << "*** Meeeeowwww ***" << RESET << std::endl;
}