// #include "ClapTrap.hpp"

// static void sep(const std::string& title) {
//     std::cout << "\n==== " << title << " ====\n";
// }

// int main() {
//     sep("Forme canonique");
//     ClapTrap def;
//     ClapTrap a("Alpha");
//     ClapTrap b(a);
//     def = b;

//     sep("Cas normal");
//     a.attack("Dummy");
//     a.takeDamage(3);
//     a.beRepaired(2);

//     sep("Énergie = 0 (attaque)");
//     ClapTrap e("Energyless");
//     for (int i = 0; i < 11; ++i)
//         e.attack("TrainingBag");

//     sep("Énergie = 0 (réparation impossible)");
//     e.beRepaired(5);

//     sep("HP = 0 (mort), actions interdites");
//     ClapTrap z("ZeroHP");
//     z.takeDamage(7);
//     z.takeDamage(7);
//     z.attack("Afterlife");
//     z.beRepaired(10);

//     sep("Réparation avec énergie > 0 et HP > 0");
//     ClapTrap r("Repairer");
//     r.takeDamage(6);
//     r.beRepaired(5);
//     r.attack("Target");

//     sep("Indépendance des copies");
//     ClapTrap c1("Original");
//     ClapTrap c2 = c1;
//     c2.attack("Target");
//     c1.takeDamage(2);

//     sep("Fin du programme (ordre de destruction)");
//     return 0;
// }

#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Alpha");

    a.attack("Target1");
    a.takeDamage(5);
    a.beRepaired(3);

    for (int i = 0; i < 12; i++)
        a.attack("Dummy");

    a.takeDamage(50);
    a.attack("After death");
    a.beRepaired(10);
}
