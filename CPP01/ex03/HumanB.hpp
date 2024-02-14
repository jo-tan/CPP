#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string colnst &name, Weapon const type);
        ~HumanA(void);

        void    attack();
    private:
        std::string name;
        Weapon const &weapon;
};

#endif