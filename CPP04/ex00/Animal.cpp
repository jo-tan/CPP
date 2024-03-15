/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:55:31 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:55:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():_type("Animal")
{
    std::cout << GREY << "Class Animal: Default Constructor" << RESET << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << GREY << "Class Animal: Copy Constructor" << RESET << std::endl;
}

Animal::~Animal()
{
    std::cout << GREY << "Class Animal: Destructor" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    std::cout << GREY << "Class Animal: Assignation Operator" << RESET << std::endl;
    if (this == &obj)
        return *this;
    this->_type = obj._type;
    return *this;
}

void    Animal::makeSound()const
{
    std::cout << BLUE << "... Animal doesn't have a specific sound ..." << RESET << std::endl;
}

std::string Animal::getType()const
{
    return _type;
}