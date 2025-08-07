#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 12;

    Zombie* horde = zombieHorde(N, "");

    if (!horde) {
        std::cout << "Horde creation failed." << std::endl;
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        std::string name = "Zombie";
        name += static_cast<char>('A' + i);
        horde[i].setName(name);  
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
