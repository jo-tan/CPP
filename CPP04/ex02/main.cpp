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
    std::cout << "**** TEST 1: use make sound function for cats and dogs only ****" << std::endl; 
    std::cout << "=== CONSTRUCT ===" << std::endl;
    {
        const Animal* meta[8];

        for(int i = 0; i < 8; i++)
        {
            if (i % 2)
            {
                meta[i] = new Dog();
                if (meta[i] == NULL)
                {
                    perror ("Main(): new Dog() allocation failed");
                    std::cerr << "Exit the program..." << std::endl;
                    exit(1);
                }
            }
            else
            {
                meta[i] = new Cat();
                if (meta[i] == NULL)
                {
                    perror ("Main(): new Cat() allocation failed");
                    std::cerr << "Exit the program..." << std::endl;
                    exit(1);
                }
            }
        }

        std::cout << "\n=== Make Sounds ===" << std::endl;
        for(int i = 0; i < 8; i++)
        {
            std::cout << meta[i]->getType() << ": ";
            meta[i]->makeSound();
        }

        std::cout << "\n=== DECONSTRUCT ===" << std::endl;
        for(int i = 0; i < 8; i++)
        {
            delete meta[i];
        }
    }

    std::cout << "\n\n**** TEST 2: uncomment below to see error due to pure virtual function ****\n" << std::endl;
    
    //const Animal* test = new Animal();

return 0;
}