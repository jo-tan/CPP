/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:00:02 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 09:00:58 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"


class ScavTrap: virtual public ClapTrap
{
	private:
		bool _gate;
	public: 
		ScavTrap();
		ScavTrap(std::string &name);
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &object);

		void	guardGate();
		void	attack(const std::string &target);
		
};

