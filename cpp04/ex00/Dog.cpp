#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << type <<" Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)  {
    this->type = other.type;
    std::cout << type <<" Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << type <<" Copy assigned" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << type <<" Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << type <<" Wouaf Wouaf.." << std::endl;
}