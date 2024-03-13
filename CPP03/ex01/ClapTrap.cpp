/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:55:31 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:55:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _HitPnt(10), _EnergyPnt(10), _AttDamage(0), _name("anonymous " + std::to_string(_anonymous))
{
    std::cout << GREY << "ClapTrap default Constructor: Initialize " << _name << " attributs: ";
    std::cout << "hit points (10), energy points (10), attack damage (0) and ";
    std::cout << "name (" << CYAN << _name << GREY << ")" << RESET << std::endl << std::endl;
    _anonymous++;
}

ClapTrap::ClapTrap(std::string &name) : _HitPnt(10), _EnergyPnt(10), _AttDamage(0), _name(name)
{
    std::cout << GREY << "ClapTrap Copy Constructor: Initialize " << name << " attributs: ";
    std::cout << "hit points (10), energy points (10), attack damage (0) and ";
    std::cout << "name (" << CYAN << name << GREY << ")" << RESET << std::endl << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _HitPnt(10), _EnergyPnt(10), _AttDamage(0), _name(name)
{
    std::cout << GREY << "ClapTrap Copy Constructor: Initialize " << name << " attributs: ";
    std::cout << "hit points (10), energy points (10), attack damage (0) and ";
    std::cout << "name (" << CYAN << name << GREY << ")" << RESET << std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << GREY << "ClapTrap Copy Constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << CYAN << _name << RESET << " has been destroyed. RIP." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &object)
{
    std::cout << GREY << "ClapTrap assignment operator called" << RESET << std::endl;
    if (this != &object)
    {
        _name = object._name;
        _HitPnt = object._HitPnt;
        _EnergyPnt = object._EnergyPnt;
        _AttDamage = object._AttDamage;
    }
    return *this;
}

void    ClapTrap::attack(const std::string &target)
{
    std::cout << GREY << "ClapTrap member function, attack() called" << RESET << std::endl;
    if (this->_EnergyPnt <= 0 || this->_HitPnt <= 0)
    {
        std::cout << this->_name << " is out of energy or hit points." << std::endl;
        std::cout << "Status: Energy(" << this->_EnergyPnt << ") Hit Points(" << this->_HitPnt << ")" << std::endl;
        return ;
    }
    this->_HitPnt -= 1;
    std::cout << "ClapTrap " << CYAN << this->_name << RESET << " attacks ";
    std::cout << MAGENTA << target << RESET << ", causing " << YELLOW << _AttDamage << RESET << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << GREY << "ClapTrap member function, takeDamage() called" << RESET << std::endl;
    std::cout << CYAN << this->_name << RESET << " takes " << YELLOW << amount << RESET << " damage!" << std::endl;
    if (amount > this->_EnergyPnt)
    {
        this->_EnergyPnt = 0;
        std::cout << CYAN << this->_name << RESET << " pass out" << std::endl;
        std::cout << CYAN << this->_name << RESET << " Status: Energy(" << this->_EnergyPnt << ")" << std::endl;
        return ;
    }
    this->_EnergyPnt -= amount;
    std::cout << "Current Status: Energy(" << this->_EnergyPnt << ")" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << GREY << "ClapTrap member function, beRepaired() called" << RESET << std::endl;
    if (this->_EnergyPnt <= 0 || this->_HitPnt <= 0)
    {
        std::cout << this->_name << " is out of energy or hit points." << std::endl;
        std::cout << "Status: Energy(" << this->_EnergyPnt << ") Hit Points(" << this->_HitPnt << ")" << std::endl;
        return ;
    }
    if (this->_EnergyPnt < amount)
    {
        std::cout << this->_name << "does not have enough energy points required for repair..." << std::endl;
        std::cout << "Amount request: " << amount << " Amount of Energy Points: " << _EnergyPnt << std::endl;
        return ;
    }
    _EnergyPnt -= amount;
    _HitPnt += amount;
    std::cout << "ClapTrap " << this->_name << "repaired ";
    std::cout << amount << " of hit points." << std::endl;
}

void    ClapTrap::printStatus()
{
    std::cout << GREY << "ClapTrap member function, printStatus() called" << RESET << std::endl;
    std::cout << "=== STATUS TABLE ===" << std::endl;
    std::cout << CYAN << _name << RESET << std::endl;
    std::cout << "Hit Points: " << _HitPnt << std::endl;
    std::cout << "Energy Points: " << _EnergyPnt << std::endl;
    std::cout << "Attack Damage: " << _AttDamage << std::endl;
    std::cout << "====================" << std::endl;
}