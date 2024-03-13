/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:10:14 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/13 16:11:51 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(std::string &name);
        DiamondTrap(const DiamondTrap &copy);
        ~DiamondTrap();

        DiamondTrap &operator=(const DiamondTrap &object);
    
        void    whoAmI();

};

#endif
