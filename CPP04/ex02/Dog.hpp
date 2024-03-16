/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:25:59 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/16 08:26:01 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(const Dog &copy);
        ~Dog();

        Dog &operator=(const Dog &obj);
        
        void makeSound() const;
        void newIdea(size_t num, std::string idea);
        std::string getIdea(size_t i) const;
        const std::string* getIdeaAddress(size_t i) const;
};
