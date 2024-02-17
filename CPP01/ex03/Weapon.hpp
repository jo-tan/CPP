/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:37:24 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 06:37:26 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <iostream>
#include <string>

class Weapon
{
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();

        std::string const &getType(void) const;
        void    setType(std::string type);
    private:
        std::string _type;
};

#endif
