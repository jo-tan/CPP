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
    _HitPnt = ScavTrap::_HitPnt;
    _EnergyPnt = FragTrap::_EnergyPnt;
    _AttDamage = FragTrap::_AttDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
    std::cout << GREY << "DiamondTrap copy constructor called" << RESET << std::endl;
    _HitPnt = ScavTrap::_HitPnt;
    _EnergyPnt = FragTrap::_EnergyPnt;
    _AttDamage = FragTrap::_AttDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << GREY << "DiamondTrap destructor called" << RESET << std::endl;
}

