/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:37:12 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 06:37:14 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string type):_type(type)
{}

Weapon::~Weapon(void)
{}

std::string const   &Weapon::getType(void) const
{
    return this->_type;
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}
