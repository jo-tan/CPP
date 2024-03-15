#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << GREY << "Class Dog: Default Constructor" << RESET << std::endl;
    _type = "Dog";
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        perror ("Dog: new Brain() alloDogion failed");
        std::cerr << "Exit the program..." << std::endl;
        exit(1);
    }
}

Dog::Dog(const Dog &copy) : Animal()
{
    *this = copy;
    std::cout << GREY << "Class Dog: Copy Constructor" << RESET << std::endl;
}

Dog::~Dog()
{
    std::cout << GREY << "Class Dog: Deconstructor" << RESET << std::endl;
    delete this->_brain;
}

/* 1. check for self-assignment 2. copy non-pointer member
3. if existing _brain is not null, delete the old one*/
Dog &Dog::operator=(const Dog &obj)
{
    std::cout << GREY << "Class Dog: Assignation Operator" << RESET << std::endl;
    if(this != &obj)
    {
        this->_type = obj._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain();
        if (this->_brain == NULL)
        {
            perror ("Dog: new Brain() allocation failed");
            std::cerr << "Exit the program..." << std::endl;
            exit(1);
        }
        *this->_brain = *obj._brain;
    }
    return *this;
}

void    Dog::makeSound()const
{
    std::cout << YELLOW << "*** Woooof! ***" << RESET << std::endl;
}