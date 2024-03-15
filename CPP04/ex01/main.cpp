/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:54:25 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "TEST 1: check memory leaks" << std::endl; 
    std::cout << "=== CONSTRUCT ===" << std::endl;
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << "\n=== DECONSTRUCT ===" << std::endl;
        delete dog;
        delete cat;
    }

    std::cout << "\n\n**** TEST WRONG ANIMAL and WRONG CAT ****\n" << std::endl;
    std::cout << "=== CONSTRUCT ===" << std::endl;
    {
        
    }

return 0;
}