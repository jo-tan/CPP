#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string const &name, Weapon &weapon);
        ~HumanA();

        void    attack(void) const;
    private:
        std::string _name;
        Weapon &_weapon;
};
#endif