// #include "ScavTrap.hpp"

// static void sep(const std::string& t) { std::cout << "\n==== " << t << " ====\n"; }

// int main() {
//     sep("Construction chain");
//     ScavTrap s("Sentinel");

//     sep("Attack uses ScavTrap message");
//     s.attack("Intruder");

//     sep("Guard gate mode");
//     s.guardGate();

//     sep("Energy drain");
//     for (int i = 0; i < 60; ++i) s.attack("Dummy");

//     sep("HP=0 forbids actions");
//     ScavTrap z("Zero");
//     z.takeDamage(150);
//     z.attack("Afterlife");
//     z.beRepaired(10);

//     sep("Copy and assign keep ScavTrap semantics");
//     ScavTrap a("A");
//     ScavTrap b(a);
//     b.attack("X");
//     a = b;
//     a.guardGate();

//     sep("Destruction order");
//     return 0;
// };

#include "ScavTrap.hpp"
#include <iostream>

static void sep(const std::string& t) {
    std::cout << "\n==== " << t << " ====\n";
}

int main() {
    sep("Construction");
    ScavTrap s("Sentinel");

    sep("Attack");
    s.attack("Intruder");

    sep("Guard mode");
    s.guardGate();

    sep("Energy drain");
    for (int i = 0; i < 3; ++i) s.attack("Dummy");

    sep("HP=0");
    ScavTrap z("Zero");
    z.takeDamage(100);
    z.attack("Ghost");

    sep("Copy & assign");
    ScavTrap a("A");
    ScavTrap b(a);
    b = a;

    sep("Destruction");
    return 0;
}

