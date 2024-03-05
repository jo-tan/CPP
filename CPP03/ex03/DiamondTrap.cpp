/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:11:53 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 09:12:11 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    std::cout << GREY << "DiamondTrap default constructor called" << RESET << std::endl;
    _name += "_clap_name";
    std::cout << "1" << "\n";
    _EnergyPnt = FragTrap::_EnergyPnt;
    std::cout << "2" << "\n";
    _AttDamage = FragTrap::_AttDamage;
    std::cout << "3" << "\n";
    _HitPnt = ScavTrap::_HitPnt;
    std::cout << "Final status of DiamondTrap default constructor" << "\n";
    ClapTrap::printStatus();
    std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
    std::cout << GREY << "DiamondTrap copy constructor called" << RESET << std::endl;
    _EnergyPnt = FragTrap::_EnergyPnt;
    _AttDamage = FragTrap::_AttDamage;
    _HitPnt = ScavTrap::_HitPnt;
    std::cout << "Final status of DiamondTrap default constructor" << "\n";
    ClapTrap::printStatus();
    std::cout << std::endl;
}

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name + "_clap_name")
{
    std::cout << GREY << "DiamondTrap copy constructor called" << RESET << std::endl;
    _EnergyPnt = FragTrap::_EnergyPnt;
    _AttDamage = FragTrap::_AttDamage;
    _HitPnt = ScavTrap::_HitPnt;
    std::cout << "Final status of DiamondTrap default constructor" << "\n";
    ClapTrap::printStatus();
    std::cout << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << GREY << "DiamondTrap destructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &object)
{
    std::cout << GREY << "Diamond assigned operator called" << RESET << std::endl;
    if (this != &object)
    {
        _name = object._name;
        _HitPnt = object._HitPnt;
        _EnergyPnt = object._EnergyPnt;
        _AttDamage = object._AttDamage;
    }
    return *this;
}

void    DiamondTrap::whoAmI()
{
    std::cout << GREY << "Diamond public member function: whoAmI() called" << RESET << std::endl;
    std::cout << CYAN << this->_name << RESET << " wondering who it is.... But no one could answer this." << std::endl << std::endl;

}
