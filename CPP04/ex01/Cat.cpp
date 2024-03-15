#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << GREY << "Class Cat: Default Constructor" << RESET << std::endl;
    _type = "Cat";
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        perror ("Cat: new Brain() allocation failed");
        std::cerr << "Exit the program..." << std::endl;
        exit(1);
    }
}

Cat::Cat(const Cat &copy) : Animal()
{
    *this = copy;
    std::cout << GREY << "Class Cat: Copy Constructor" << RESET << std::endl;
}

Cat::~Cat()
{
    std::cout << GREY << "Class Cat: Deconstructor" << RESET << std::endl;
    delete this->_brain;
}

/* 1. check for self-assignment 2. copy non-pointer member
3. have a temp Brain to copy the content 4. if existing _brain is not null, delete the old one*/
Cat &Cat::operator=(const Cat &obj)
{
    std::cout << GREY << "Class Cat: Assignation Operator" << RESET << std::endl;
    if(this != &obj)
    {
        this->_type = obj._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain();
        if (this->_brain == NULL)
        {
            perror ("Cat: new Brain() allocation failed");
            std::cerr << "Exit the program..." << std::endl;
            exit(1);
        }
        *this->_brain = *obj._brain;
    }
    return *this;
}

void    Cat::makeSound()const
{
    std::cout << YELLOW << "*** Meeeeowwww ***" << RESET << std::endl;
}