/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:54:25 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{

    DiamondTrap a;
    a.attack("a weak human");
    a.attack("a weak human");
    a.attack("a weak human");
    a.attack("a weak human");
    a.takeDamage(60);
    a.takeDamage(41);
    a.printStatus();

    /*DiamondTrap b;
    b.whoAmI();
    DiamondTrap c("??WONDERER??");
    c.highFivesGuys();*/

    return 0;
}