/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/22 18:21:31 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::string name = "mini A";
    std::cout << "summon a ClapTrap" << std::endl;
    ClapTrap a(name);
    a.printStatus();

    std::cout << "Instruct ClapTrap a to attack enemy one twice:" << std::endl ;
    a.attack("the Dragon");
    a.attack("the Dragon");
    a.printStatus();
    std::cout << std::endl;
    std::cout << "Instruct ClapTrap a to repaire 2 points:" << std::endl;
    a.beRepaired(2);
    a.printStatus();
    std::cout << std::endl;
    std::cout << "Instruct ClapTrap a to repaire 15 points:" << std::endl;
    a.beRepaired(15);
    std::cout << std::endl;
    std::cout << "take super damage" << std::endl;
    a.takeDamage(500);
    std::cout << std::endl;
    a.printStatus();

    std::cout << "TEST 2: summon a ClapTrap without name" << std::endl;
    ClapTrap b;
    b.printStatus();

    b.attack("the Dragon");
    b.beRepaired(1);
    b.printStatus();
    std::cout << std::endl;

    std::cout << "TEST 3: summon a ClapTrap without name again" << std::endl;
    ClapTrap c;
    c.printStatus();
    std::cout << std::endl;

    std::cout << "TEST 3: summon multiple ClapTraps without name" << std::endl;
    ClapTrap d;
    ClapTrap e;
    ClapTrap f;
    ClapTrap g;
    ClapTrap h;
    ClapTrap i;
    std::cout << std::endl;
}