#include "Zombie.hpp"

int main(void)
{
    Zombie  *zombies = NULL;
    int     size;

    size = 3;
    std::cout << "=== summon horde of Zombies " << size << " times ===" << std::endl;
    zombies = zombieHorde(size, "Phineas");
    for(int i = 0; i < size; ++i)
        zombies[i].annouce();
    delete[] zombies;
    std::cout << std::endl;

    size = -2;
    std::cout << "=== summon horde of Zombies " << size << " times ===" << std::endl;
    zombies = zombieHorde(size, "Ferb");
    for(int i = 0; i < size; ++i)
        zombies[i].annouce();
    delete[] zombies;
    std::cout << std::endl;

    return 0;
}