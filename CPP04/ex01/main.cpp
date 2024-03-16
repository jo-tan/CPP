/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/16 09:04:19 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "**** TEST 1: Animal array (half Dog/half Cat) ****" << std::endl; 
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
                    std::cerr << "Main(): new Dog() allocation failed\nExit the program..." << std::endl;
                    exit(1);
                }
            }
            else
            {
                meta[i] = new Cat();
                if (meta[i] == NULL)
                {
                    std::cerr << "Main(): new Cat() allocation failed\nExit the program..." << std::endl;
                    exit(1);
                }
            }
        }

        std::cout << "\n=== DECONSTRUCT ===" << std::endl;
        for(int i = 0; i < 8; i++)
        {
            delete meta[i];
        }
    }

    std::cout << "\n\n**** TEST 2: check heap address for deep copy ****\n" << std::endl;
    {
        std::cout << "=== create catA and assign ideas to catA ===" << std::endl;
        Cat *catA = new Cat();
        if (catA == NULL)
        {
            std::cerr << "Main(): catA allocation failed\nExit the program..." << std::endl;
            exit(1);
        }
        catA->newIdea(0, "Hungry....");
        catA->newIdea(1, "What time is it?");
        catA->newIdea(2, "FEED ME, HUMAN!");
        catA->newIdea(422, "???"); // should return error msg

        Cat *catB = new Cat(*catA);
        if (catB == NULL)
        {
            std::cerr << "Main(): catB allocation failed\nExit the program..." << std::endl;
            exit(1);
        }
        
        Cat catD;
        Cat catC = catD;
        
        std::cout << "\n**** PROOF OF DEEP COPY ****" << std::endl;
        std::cout << "CatA's heap address: " << static_cast<void*>(catA) << std::endl;
        std::cout << "CatB's heap address: " << static_cast<void*>(catB) << std::endl;
        std::cout << "CatC's address: " << std::__addressof(catC) << std::endl;
        std::cout << "CatD's address: " << std::__addressof(catD) << std::endl;

        std::cout << "\n**** Compare CatA and CatB's ideas ****" << std::endl;
        std::cout << "\n=== catA's ideas ===" << std::endl;
        for (int i = 0; i < 100; i++)
        {
            if (!catA->getIdea(i).empty())
                std::cout << i  << " idea(" << catA->getIdeaAddress(i) << "): "<< catA->getIdea(i) << std::endl;
        }
        std::cout << "\n=== catB's ideas ===" << std::endl;
        for (int i = 0; i < 100; i++)
        {
            if (!catA->getIdea(i).empty())
                std::cout << i  << " idea(" << catB->getIdeaAddress(i) << "): "<< catB->getIdea(i) << std::endl;
        }
        std::cout << "\n=== DECONSTRUCT ===" << std::endl;
        delete catA;
        delete catB;
    }

return 0;
}