#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <iostream>
#include <string>

class Weapon
{
    public:
        Weapon();
        ~Weapon();

        void    getType() const;
        void    setType(std::string const &type);
    private:
        std::string _type;
};

#endif