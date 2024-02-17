#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string const &name);
        ~HumanB();

        void    attack(void) const;
        void    setWeapon(Weapon &weapon);
    private:
        std::string _name;
        Weapon *_weapon;
};

#endif