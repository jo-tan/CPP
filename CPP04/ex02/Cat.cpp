/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:25:28 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/16 08:42:09 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << GREY << "Class Cat: Default Constructor" << RESET << std::endl;
    _type = "Cat";
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cerr << "Cat: new Brain() allocation failed\nExit the program..." << std::endl;
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
3. assign new Brain to new object, if malloc failed, exit 1 */
Cat &Cat::operator=(const Cat &obj)
{
    std::cout << GREY << "Class Cat: Assignation Operator" << RESET << std::endl;
    if(this != &obj)
    {
        this->_type = obj._type;
        this->_brain = new Brain();
        if (this->_brain == NULL)
        {
            std::cerr << "Cat: new Brain() allocation failed\nExit the program..." << std::endl;
            exit(1);
        }
        *this->_brain = *obj._brain;
    }
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << YELLOW << "*** Meeeeowwww ***" << RESET << std::endl;
}

void Cat::newIdea(size_t num, std::string idea)
{
    this->_brain->newIdea(num, idea);
}

std::string Cat::getIdea(size_t i) const
{
    return this->_brain->getIdea(i);
}

const std::string* Cat::getIdeaAddress(size_t i) const
{
    return this->_brain->getIdeaAddress(i);
}
