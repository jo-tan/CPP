#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon)
 : _name(name), _weapon(weapon)
{}

HumanA::~HumanA()
{
	std::cout << _name << " finish the attack." << std::endl <<std::endl;
};

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType();
	std::cout << std::endl;
}
