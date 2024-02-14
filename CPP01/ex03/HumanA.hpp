#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string const &name, Weapon const type);
        ~HumanA();

        void    attack();
    private:
        std::string name;
        Weapon *weapon;
};
#endif