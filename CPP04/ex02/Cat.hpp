#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(const Cat &copy);
        ~Cat();

        Cat &operator=(const Cat &obj);
        
        void makeSound() const;
        void newIdea(size_t num, std::string idea);
        std::string getIdea(size_t i) const;
        const std::string* getIdeaAddress(size_t i) const;
};