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

#include "ScavTrap.hpp"

int main()
{
    std::string name = "Scavvy";
    ScavTrap a(name);
    a.attack("the Dragon");
    a.printStatus();

    ScavTrap b;
    ScavTrap c;
    b.guardGate();
    b.printStatus();
    c.printStatus();
    return 0;
}
