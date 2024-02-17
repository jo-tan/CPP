/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:36:20 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 06:36:21 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string const &name, Weapon &weapon);
        ~HumanA();

        void    attack(void) const;
    private:
        std::string _name;
        Weapon &_weapon;
};
#endif
