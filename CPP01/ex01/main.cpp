/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:44:28 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 11:12:16 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  *zombies = NULL;
    int     size;

    size = 3;
    std::cout << "=== summon horde of Zombies " << size << " times ===" << std::endl;
    zombies = zombieHorde(size, "Phineas");
    for(int i = 0; i < size; ++i)
        zombies[i].annouce();
    delete[] zombies;
    std::cout << std::endl;

    size = -2;
    std::cout << "=== summon horde of Zombies " << size << " times ===" << std::endl;
    zombies = zombieHorde(size, "Ferb");
    for(int i = 0; i < size; ++i)
        zombies[i].annouce();
    delete[] zombies;
    std::cout << std::endl;

    size = 1;
    std::cout << "=== summon horde of Zombies " << size << " times ===" << std::endl;
    zombies = zombieHorde(size, "");
    for(int i = 0; i < size; ++i)
        zombies[i].annouce();
    delete[] zombies;
    std::cout << std::endl;

    return 0;
}
