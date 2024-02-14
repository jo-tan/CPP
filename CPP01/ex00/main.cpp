#include "Zombie.hpp"

int main(void)
{
    Zombie  *heapZombie = NULL;

    std::cout << "=== summon zombie on stack ===" << std::endl;
    randomChump("Phineas");

    std::cout << "=== summon zombie on heap ===" << std::endl;
    heapZombie = newZombie("Ferb");
    delete heapZombie;
    std::cout << "=== END ===" << std::endl;
    return 0;
}