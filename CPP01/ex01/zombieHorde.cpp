#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *zombies;

    if (N <= 0)
    {
        std::cout << "You can't summon zombies less then 0 time." << std::endl;
        return NULL;
    }

    zombies = new Zombie[N];
    for (int i = 0; i < N; ++i)
        zombies[i].setName(name);
    return zombies;
}