#include "Zombie.hpp"

Zombie* newZombie(std::string name);
Zombie* randomChump(std::string name);

int main() {
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    delete heapZombie;

    std::cout <<"----------------------------------" << std::endl;

    randomChump("Stacky");
    return 0;
}