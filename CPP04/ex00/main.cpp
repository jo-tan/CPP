/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:54:22 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/16 08:22:33 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== CONSTRUCT ===" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        const Animal* dogPtr = dog; // dogPtr points to same memory allocation as dog (class Dog)
        const Animal* catPtr(cat); // similar to dogPtr, passing cat to pointer catPtr

        std::cout << "\n--- GET TYPE ---" << std::endl;
        std::cout << "dog: " << dog->getType() << " " << std::endl;
        std::cout << "cat: " << cat->getType() << " " << std::endl;
        std::cout << "\n--- GET TYPE : pointer to pointer ---" << std::endl;
        std::cout << "dogPtr: " << dogPtr->getType() << " " << std::endl;
        std::cout << "catPtr: " << catPtr->getType() << " " << std::endl;

        std::cout << "\n--- MAKE SOUND ---" << std::endl;
        std::cout << "cat: ";
        cat->makeSound(); //will output the cat sound!
        std::cout << "dog: ";
        dog->makeSound();
        std::cout << "meta: ";
        meta->makeSound();
        std::cout << "dogPtr: ";
        dogPtr->makeSound();
        std::cout << "catPtr: ";
        catPtr->makeSound();

        std::cout << "\n=== DESTRUCT ===" << std::endl;
        delete meta;
        delete dog;
        delete cat;
    }

    std::cout << "\n\n**** TEST WRONG ANIMAL and WRONG CAT ****\n" << std::endl;
    std::cout << "=== CONSTRUCT ===" << std::endl;
    {
        const WrongAnimal* base = new WrongAnimal();
        const WrongAnimal* derived = new WrongCat();

        std::cout << "\n--- GET TYPE ---" << std::endl;
        std::cout << base->getType() << " " << std::endl;
        std::cout << derived->getType() << " " << std::endl;

        std::cout << "\n--- MAKE SOUND ---" << std::endl;
        base->makeSound(); 
        derived->makeSound(); //will output the wrong cat sound

        std::cout << "\n=== DESTRUCT ===" << std::endl;
        delete base;
        delete derived;
    }

return 0;
}
