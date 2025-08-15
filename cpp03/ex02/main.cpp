// #include "FragTrap.hpp"
// #include <iostream>

// static void sep(const std::string& t){ std::cout << "\n==== " << t << " ====\n"; }

// int main() {
//     sep("Construct");
//     FragTrap f("Fraggy");

//     sep("High five");
//     f.highFivesGuys();

//     sep("Attack & drain energy");
//     for (int i = 0; i < 102; ++i) f.attack("Dummy");

//     sep("HP=0");
//     FragTrap z("Zero");
//     z.takeDamage(150);
//     z.attack("Afterlife");
//     z.beRepaired(10);

//     sep("Copy/Assign");
//     FragTrap a("A");
//     FragTrap b(a);
//     b.beRepaired(5);
//     a = b;

//     sep("Destruct");
//     return 0;
// };


#include "FragTrap.hpp"

int main() {
    FragTrap f1("Alpha");

    f1.attack("Target1");
    f1.highFivesGuys();

  
    for (int i = 0; i < 10; i++) {
        f1.attack("Dummy");
    }

    FragTrap f2 = f1;
    f2.attack("Target2");

    FragTrap f3;
    f3 = f1;
    f3.attack("Target3");

    return 0;
}


