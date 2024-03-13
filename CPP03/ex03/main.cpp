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
    std::cout << "\n\n### TESTING CLAPTRAP ###\n" << std::endl;
	{
        std::cout << BLUE << "\nConstructing" << RESET << std::endl;
        ClapTrap a;

        std::cout << BLUE << "\nTesting" << RESET << std::endl;
        a.printStatus();
        a.attack("a weak human");
        std::cout << BLUE << "\nDeconstructing" << RESET << std::endl;
    }
    std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
        std::cout << BLUE << "\nConstructing" << RESET << std::endl;
        ScavTrap b;

        std::cout << BLUE << "\nTesting" << RESET << std::endl;
        b.printStatus();
        b.guardGate();
        b.guardGate();
        std::cout << BLUE << "\nDeconstructing" << RESET << std::endl;
    }
    std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
        std::cout << BLUE << "\nConstructing" << RESET << std::endl;
        FragTrap c;

        std::cout << BLUE << "\nTesting" << RESET << std::endl;
        c.printStatus();
        c.highFivesGuys();
        std::cout << BLUE << "\nDeconstructing" << RESET << std::endl;
    }

    std::cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		std::cout << BLUE << "\nConstructing" << RESET << std::endl;
		DiamondTrap x;
		DiamondTrap y("???");
		DiamondTrap z(x);

		std::cout << BLUE << "\nTesting" << RESET << std::endl;
		x.whoAmI();
		x.attack("some random guy");
		y.whoAmI();
		y.attack("a testing object");
        y.takeDamage(60);
        y.takeDamage(41);
        y.printStatus();
		z.whoAmI();
		std::cout << BLUE << "\nDeconstructing" << RESET << std::endl;
	}

    return 0;
}