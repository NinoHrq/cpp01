#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << type <<" Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    this->type = other.type;
    std::cout << type <<" Copy Constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << type <<" Copy assigned" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << type <<" Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << type << " Some weird WrongAnimal sound..." << std::endl;
}