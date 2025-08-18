#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << type <<" Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->type = other.type;
    std::cout << type <<" Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << type <<" Copy assigned" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << type <<" Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << type << " Miaou Miaou.." << std::endl;
}