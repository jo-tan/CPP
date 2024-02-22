/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:44 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/22 18:20:52 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class ClapTrap
{
private:
    int _HitPnt;
    int _EnergyPnt;
    int _AttDamage;
    std::string _name;
    
public:
    ClapTrap();
    ClapTrap(std::string &name);
    ~ClapTrap();

    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap() : _HitPnt(10), _EnergyPnt(10), _AttDamage(0), _name("anonymous")
{
    std::cout << "Initialize ClapTrap attributs: ";
    std::cout << "hit points (10), energy points (10), attack damage (0) and ";
    std::cout << "name (anonymous)" << std::endl;
}

ClapTrap::ClapTrap(std::string &name) : _HitPnt(10), _EnergyPnt(10), _AttDamage(0), _name(name)
{
    std::cout << "Initialize ClapTrap attributs: ";
    std::cout << "hit points (10), energy points (10), attack damage (0) and ";
    std::cout << "name (" << name << ")" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap is been destroyed. RIP." << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->_EnergyPnt <= 0 || this->_HitPnt <= 0)
    {
        std::cout << this->_name << " is out of energy or hit points." << std::endl;
        std::cout << "Status: Energy(" << this->_EnergyPnt << ") Hit Points(" << this->_HitPnt << ")" << std::endl;
        return ;
    }
    this->_HitPnt -= 1;
    std::cout << "ClapTrap " << this->_name << "attacks ";
    std::cout << target << ", causing <damage> points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_EnergyPnt <= 0 || this->_HitPnt <= 0)
    {
        std::cout << this->_name << " is out of energy or hit points." << std::endl;
        std::cout << "Status: Energy(" << this->_EnergyPnt << ") Hit Points(" << this->_HitPnt << ")" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << "attacks ";
    std::cout << target << ", causing <damage> points of damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_EnergyPnt <= 0 || this->_HitPnt <= 0)
    {
        std::cout << this->_name << " is out of energy or hit points." << std::endl;
        std::cout << "Status: Energy(" << this->_EnergyPnt << ") Hit Points(" << this->_HitPnt << ")" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << "attacks ";
    std::cout << target << ", causing <damage> points of damage!" << std::endl;
}