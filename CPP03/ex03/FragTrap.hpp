/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:06:12 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 09:07:10 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public: 
		FragTrap();
		FragTrap(std::string &name);
		FragTrap(const std::string &name);
		~FragTrap();

		FragTrap &operator=(const FragTrap &object);

		void	highFivesGuys();
};

#endif
