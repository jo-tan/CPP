/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:45:01 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 11:11:50 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("zombie")
{}

Zombie::Zombie(std::string name) : _name(name)
{}

Zombie::~Zombie()
{
    std::cout << this->_name << " has been sent back." << std::endl;
}

void    Zombie::setName(std::string const &name)
{
    this->_name = name;
}

void    Zombie::annouce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
