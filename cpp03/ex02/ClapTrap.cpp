#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) 
{
    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& n)
    : name(n), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor called for "<< name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy Constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "Copy assigned" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if(hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of HP and can't attack!" << std::endl;
        return; 
    }
    if(energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
        return;        
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " is already down!\n";
        return;
    }
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage! HP now: " << hitPoints << "\n";
    if (hitPoints == 0)
        std::cout << "[ClapTrap] " << name << " is now down!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " can't repair, HP is 0!\n";
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to repair!\n";
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " HP! HP now: " << hitPoints << "\n";
}