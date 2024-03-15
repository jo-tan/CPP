#include "Brain.hpp"

Brain::Brain()
{
    std::cout << GREY << "Class Brain: Default Constructor" << RESET<< std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << GREY << "Class Brain: Copy Constructor" << RESET<< std::endl;
    *this = copy;
}
    
Brain::~Brain()
{
    std::cout << GREY << "Class Brain: Destructor" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
    std::cout << GREY << "Class Brain: Assignation Operator" << RESET << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i < 100; i++)
        {
            if (!obj._ideas[i].empty())
                this->_ideas[i] = obj._ideas[i];
        }
    }
    return *this;
}

void Brain::newIdea(size_t num, std::string idea)
{
    if (num > 100)
        std::cout << RED << "the Brain can't take more than 100 ideas" << RESET << std::endl;
    else
        this->_ideas[num] = idea;
}