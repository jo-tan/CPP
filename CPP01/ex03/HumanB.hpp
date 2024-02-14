#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string const &name, Weapon const type);
        ~HumanB(void);

        void    attack();
    private:
        std::string name;
        Weapon const &weapon;
};

#endif