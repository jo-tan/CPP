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
                this->_ideas[i] = obj._ideas[i] + " *COPY*";
        }
    }
    return *this;
}

void Brain::newIdea(size_t num, std::string idea)
{
    if (num > 100)
        std::cout << RED << "the Brain can't take more than 100 ideas. This idea will be ignored." << RESET << std::endl;
    else
        this->_ideas[num] = idea;
}

std::string Brain::getIdea(size_t i) const
{
    if (i > 100)
        return "\033[31mRequest value is over array limit (100)\033[0m";
    else
        return this->_ideas[i];
}

const std::string* Brain::getIdeaAddress(size_t i) const
{
    if (i > 100)
        return NULL;
    else
        return &_ideas[i];
}