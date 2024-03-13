/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:01:11 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 09:01:30 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << GREY << "ScavTrap: default constructor called" << RESET << std::endl;
    _HitPnt = 100;
    _EnergyPnt = 50;
    _AttDamage = 20;
    _gate = false;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
    std::cout << GREY << "ScavTrap: constructor with string variable called" << RESET << std::endl;
    _HitPnt = 100;
    _EnergyPnt = 50;
    _AttDamage = 20;
    _gate = false;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << GREY << "ScavTrap: constructor with string variable called" << RESET << std::endl;
    _HitPnt = 100;
    _EnergyPnt = 50;
    _AttDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << GREY << "ScavTrap: copy constructor called: " << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << GREY << "ScavTrap destructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &object)
{
    std::cout << GREY << "ScavTrap assignment operator called" << RESET << std::endl;
    _name = object._name;
    _HitPnt = object._HitPnt;
    _EnergyPnt = object._EnergyPnt;
    _AttDamage = object._AttDamage;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << GREY << "ScavTrap member function, guardGate() called" << RESET << std::endl;
    if (this->_gate == false)
    {
        this->_gate = true;
        std::cout << CYAN << _name << GREEN << " : Gate keeper mode is ON." << RESET << std::endl;
    }
    else
        std::cout << CYAN << _name << WHITE << " is guarding the gate already." << RESET << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
    std::cout << GREY << "ScavTrap member function, attack() called" << RESET << std::endl;
    if (this->_EnergyPnt <= 0 || this->_HitPnt <= 0)
    {
        std::cout << CYAN << this->_name << RESET << " is out of energy or hit points." << std::endl;
        std::cout << "Status: Energy(" << this->_EnergyPnt << ") Hit Points(" << this->_HitPnt << ")" << std::endl;
        return ;
    }
    this->_HitPnt -= 1;
    std::cout << "ScavTrap " << CYAN << this->_name << RESET << " attacks ";
    std::cout << target << ", causing " << YELLOW << _AttDamage << RESET << " points of damage!" << std::endl;
}