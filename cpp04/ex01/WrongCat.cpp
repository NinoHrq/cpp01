#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << type <<" Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)  {
    this->type = other.type;
    std::cout << type <<" Copy Constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << type <<" Copy assigned" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << type <<" Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << type << " Miaou Miaou..(WrongCat)" << std::endl;
}