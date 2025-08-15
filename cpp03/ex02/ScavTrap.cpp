#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavDefault") {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "ScavTrap default constructor for " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string& n) : ClapTrap(n) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "ScavTrap constructor for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap Copy Constructor from " << other.name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
    std::cout << "ScavTrap Copy assigned for " << name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor for " << name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints <= 0) 
    {
        std::cout << "ScavTrap " << name << " is out of HP and can't attack!" << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " has no energy to attack!"<< std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ScavTrap " << name << " slashes " << target << " for " << attackDamage << "!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
