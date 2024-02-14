#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{}

Zombie::~Zombie()
{
    std::cout << this->_name << " has been sent back." << std::endl << std::endl;
}

void    Zombie::annouce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}