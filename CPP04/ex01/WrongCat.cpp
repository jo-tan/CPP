/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:23:26 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/16 08:26:22 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << GREY << "Class WrongCat: Default Constructor" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
    *this = copy;
    std::cout << GREY << "Class WrongCat: Copy Constructor" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << GREY << "Class WrongCat: Deconstructor" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std::cout << GREY << "Class WrongCat: Assignation Operator" << RESET << std::endl;
    if (this == &obj)
        return *this;
    this->_type = obj._type;
    return *this;
}

void    WrongCat::makeSound()const
{
    std::cout << MAGENTA << "??? @#$%^&*()_{}&^%$#@ ???" << RESET << std::endl;
}
