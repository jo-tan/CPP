/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/13 15:46:37 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "\n\n### TEST 1: summon a ClapTrap with a name ###\n" << std::endl;
    std::string name = "mini A";
    std::cout << "+++ Summon a ClapTrap +++" << std::endl;
    std::cout << BLUE << "\nConstructing" << RESET << std::endl;
    ClapTrap a(name);

    std::cout << BLUE << "\nTesting" << RESET << std::endl;
    a.printStatus();

    std::cout << "+++ Instruct ClapTrap a to attack enemy one twice +++" << std::endl ;
    a.attack("someone");
    a.attack("someone");
    a.printStatus();
    std::cout << std::endl;
    std::cout << "+++ Instruct ClapTrap a to repaire 2 points +++" << std::endl;
    a.beRepaired(2);
    a.printStatus();
    std::cout << std::endl;
    std::cout << "+++ Instruct ClapTrap a to repaire 15 points +++" << std::endl;
    a.beRepaired(15);
    std::cout << std::endl;
    std::cout << "take super damage" << std::endl;
    a.takeDamage(500);
    std::cout << std::endl;
    a.printStatus();
    
    std::cout << "\n\n###TEST 2: summon a ClapTrap without a name###\n" << std::endl;
    {
        std::cout << BLUE << "\nConstructing" << RESET << std::endl;
        ClapTrap b;
        
        std::cout << BLUE << "\nTesting" << RESET << std::endl;
        b.attack("someone");
        b.beRepaired(100);
        b.beRepaired(1);
        b.printStatus();
        std::cout << BLUE << "\nDeconstructing" << RESET << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "\n\n### TEST 3: summon a ClapTrap by coping ClapTrap mini A ###\n" << std::endl;
    std::cout << BLUE << "\nConstructing" << RESET << std::endl;
    ClapTrap c(a);
    std::cout << BLUE << "\nTesting" << RESET << std::endl;
    c.printStatus();
    std::cout << std::endl;

    std::cout << "\n\n### TEST 4: summon multiple ClapTraps without name ###\n" << std::endl;
    ClapTrap d;
    ClapTrap e;
    ClapTrap f;
    ClapTrap g;
    ClapTrap h;
    ClapTrap i;
    std::cout << BLUE << "\nDeconstructing" << RESET << std::endl;
    std::cout << std::endl;
}