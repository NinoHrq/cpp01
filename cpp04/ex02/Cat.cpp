#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << type <<" Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout << type <<" Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->type = other.type;
        *this->brain = *other.brain;
    }
    std::cout << type <<" Copy assigned" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << type <<" Destructor called" << std::endl;
    delete this->brain;
    this->brain = 0;
}

void Cat::makeSound() const {
    std::cout << type << " Miaou Miaou.." << std::endl;
}

void Cat::setIdea(int i, const std::string& s) { brain->setIdea(i, s); }
std::string Cat::getIdea(int i) const { return brain->getIdea(i); }

