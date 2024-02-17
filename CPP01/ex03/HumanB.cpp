#include "HumanB.hpp"

HumanB::HumanB(std::string const &name)
 : _name(name), _weapon(NULL)
{}

HumanB::~HumanB()
{
    std::cout << _name << " finish the attack." << std::endl <<std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " is bareheanded" << std::endl;
	else
	{
		std::cout << this->_name << " attacks with their ";
		std::cout << (this->_weapon)->getType() << std::endl;
	}
}