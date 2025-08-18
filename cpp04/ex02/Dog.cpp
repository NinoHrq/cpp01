#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << type <<" Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)  {
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout << type <<" Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
    if (this != &other){
        this->type = other.type;
        *this->brain = *other.brain;
    }
    std::cout << type <<" Copy assigned" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << type <<" Destructor called" << std::endl;
    delete this->brain;
    this->brain = 0;
}

void Dog::makeSound() const {
    std::cout << type <<" Wouaf Wouaf.." << std::endl;
}

void Dog::setIdea(int i, const std::string& s) { brain->setIdea(i, s); }
std::string Dog::getIdea(int i) const { return brain->getIdea(i); }