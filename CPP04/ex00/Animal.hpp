/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:44 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:55:24 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal &new);
        virtual ~Animal();

        Animal &operator=(const Animal &copy);
        
        virtual void makeSound()const;
}
