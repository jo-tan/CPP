/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:07:19 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 09:07:45 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << GREY << "FragTrap: default constructor" << RESET << std::endl;
    _HitPnt = 100;
    _EnergyPnt = 100;
    _AttDamage = 30;
}

FragTrap::FragTrap(std::string &name) : ClapTrap(name)
{
    _HitPnt = 100;
    _EnergyPnt = 100;
    _AttDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << GREY << "FragTrap: destructor" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &object)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &object)
    {
        _name = object._name;
        _HitPnt = object._HitPnt;
        _EnergyPnt = object._EnergyPnt;
        _AttDamage = object._AttDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << CYAN << _name << MAGENTA << " wants a high Five\nHIGH FIVE! C:" << RESET << std::endl;
}