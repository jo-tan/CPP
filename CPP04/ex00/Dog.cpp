/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:22:11 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/16 08:22:14 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
