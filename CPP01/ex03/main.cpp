#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        Weapon club = Weapon("crude spiked club");
        
        HumanA bob("Human A: Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Human B: Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("hammer");
        jim.attack();
        club.setType("bow");
        jim.attack();
    }
    return 0;
}