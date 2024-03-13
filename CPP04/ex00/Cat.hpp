#pragma once

#include "Animal.hpp"

class WrongCat
{
    protected:
        std::string _type;

    public:
        WrongCat();
        WrongCat(const WrongCat &new);
        ~WrongCat();

        WrongCat &operator=(const WrongCat &copy);
        
        void makeSound()const;
}