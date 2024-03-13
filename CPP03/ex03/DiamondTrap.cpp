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
    _name = ClapTrap::_name + "_clap_name";
    _EnergyPnt = FragTrap::_EnergyPnt;
    _AttDamage = FragTrap::_AttDamage;
    _HitPnt = ScavTrap::_HitPnt;
    std::cout << "Final status of DiamondTrap default constructor" << "\n";
    ClapTrap::printStatus();
    std::cout << std::endl;
}

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name)
{
    std::cout << GREY << "DiamondTrap copy constructor called" << RESET << std::endl;
    _name = ClapTrap::_name + "_clap_name";
    _EnergyPnt = FragTrap::_EnergyPnt;
    _AttDamage = FragTrap::_AttDamage;
    _HitPnt = ScavTrap::_HitPnt;
    std::cout << "Final status of DiamondTrap default constructor" << "\n";
    ClapTrap::printStatus();
    std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << GREY << "DiamondTrap copy constructor called" << RESET << std::endl;
    _name = ClapTrap::_name + "_clap_name";
    _EnergyPnt = FragTrap::_EnergyPnt;
    _AttDamage = FragTrap::_AttDamage;
    _HitPnt = ScavTrap::_HitPnt;
    std::cout << "Final status of DiamondTrap default constructor" << "\n";
    ClapTrap::printStatus();
    std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << GREY << "DiamondTrap Copy Constructor called" << RESET << std::endl;
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
        _name = object._name + "_clap_trap";
        _HitPnt = object._HitPnt;
        _EnergyPnt = object._EnergyPnt;
        _AttDamage = object._AttDamage;
    }
    return *this;
}

void    DiamondTrap::whoAmI()
{
    std::cout << GREY << "Diamond public member function: whoAmI() called" << RESET << std::endl;
    std::cout << "Hello, I'm a DiamondTrap named " << CYAN << this->_name << RESET << " and I'm original from ClapTrap named ";
    std::cout << CYAN << ClapTrap::_name << RESET << "." << std::endl;
}
