/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:42:11 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 10:42:13 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  *heapZombie = NULL;

    std::cout << "=== summon zombie on stack ===" << std::endl;
    randomChump("Phineas");

    std::cout << "=== summon zombie on heap ===" << std::endl;
    heapZombie = newZombie("Ferb");
    delete heapZombie;
    std::cout << "=== END ===" << std::endl;
    return 0;
}
