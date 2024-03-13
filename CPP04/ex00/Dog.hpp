#pragma once

#include "Animal.hpp"

class Dog
{
    protected:
        std::string _type;

    public:
        Dog();
        Dog(const Dog &new);
        ~Dog();

        Dog &operator=(const Dog &copy);
        
        void makeSound()const;
}