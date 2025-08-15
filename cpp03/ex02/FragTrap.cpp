#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("FragDefault") {
    hitPoints = 100; energyPoints = 100; attackDamage = 30;
    std::cout << "FragTrap default constructor for " << name << "\n";
}

FragTrap::FragTrap(const std::string& n) : ClapTrap(n) {
    hitPoints = 100; energyPoints = 100; attackDamage = 30;
    std::cout << "FragTrap constructor for " << name << "\n";
}

FragTrap::FragTrap(const FragTrap& o) : ClapTrap(o) {
    *this = o;
    std::cout << "FragTrap copy constructor from " << o.name << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) ClapTrap::operator=(other);
    std::cout << "FragTrap copy assigned for " << name << "\n";
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor for " << name << "\n";
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a positive high five!\n";
}

void FragTrap::attack(const std::string& target) {
    if(hitPoints <= 0)
    {
        std::cout << "FragTrap " << name << " is out of HP and can't attack!" << std::endl;
        return; 
    }
    if(energyPoints <= 0)
    {
        std::cout << "FragTrap " << name << " has no energy to attack!" << std::endl;
        return;        
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
