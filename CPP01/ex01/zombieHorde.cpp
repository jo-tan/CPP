/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:45:14 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 11:04:55 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *zombies;

    if (N <= 0)
    {
        std::cout << "You can't summon zombies less then 0 time." << std::endl;
        return NULL;
    }
    zombies = new Zombie[N];
    for (int i = 0; i < N; ++i)
        zombies[i].setName(name);
    return zombies;
}
