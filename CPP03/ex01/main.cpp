/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/13 16:02:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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
        b.attack("someone");
        b.takeDamage(22);
        b.beRepaired(22);
        b.printStatus();
        b.guardGate();
        b.guardGate();
        std::cout << BLUE << "\nDeconstructing" << RESET << std::endl;
    }
    return 0;
}
