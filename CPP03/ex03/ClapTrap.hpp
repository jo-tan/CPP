/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:44 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:55:24 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;241m"

static unsigned int _anonymous = 1;

class ClapTrap
{
protected:
    unsigned int _HitPnt;
    unsigned int _EnergyPnt;
    unsigned int _AttDamage;
    std::string _name;
    
public:
    ClapTrap();
    ClapTrap(std::string &name);
    ClapTrap(const std::string &name);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &object);

    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    void    printStatus();
};
