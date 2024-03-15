#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << GREY << "Class Dog: Default Constructor" << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
    *this = copy;
    std::cout << GREY << "Class Dog: Copy Constructor" << RESET << std::endl;
}

Dog::~Dog()
{
    std::cout << GREY << "Class Dog: Destructor" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout << GREY << "Class Dog: Assignation Operator" << RESET << std::endl;
    if (this == &obj)
        return *this;
    this->_type = obj._type;
    return *this;
}

void    Dog::makeSound()const
{
    std::cout << YELLOW << "*** Woooof! ***" << RESET << std::endl;
}