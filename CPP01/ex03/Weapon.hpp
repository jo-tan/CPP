#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <iostream>
#include <string>

class Weapon
{
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();

        std::string const &getType(void) const;
        void    setType(std::string type);
    private:
        std::string _type;
};

#endif