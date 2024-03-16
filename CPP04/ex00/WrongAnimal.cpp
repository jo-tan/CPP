/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:55:31 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/16 08:22:46 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << GREY << "Class WrongAnimal: Default Constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << GREY << "Class WrongAnimal: Copy Constructor" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << GREY << "Class WrongAnimal: Destructor" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout << GREY << "Class WrongAnimal: Assignation Operator" << RESET << std::endl;
    if (this == &obj)
        return *this;
    this->_type = obj._type;
    return *this;
}

void    WrongAnimal::makeSound()const
{
    std::cout << MAGENTA << "??? (Silent) ???" << RESET << std::endl;
}

std::string WrongAnimal::getType()const
{
    return _type;
}
