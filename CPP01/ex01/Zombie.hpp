/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:45:38 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 10:45:41 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        void    setName(std::string const &name);
        void    annouce(void);
    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
