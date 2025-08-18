#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal& other) :  type(other.type) {
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal Copy assigned" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
