#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Default Constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Empty idea";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain Copy Constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain Copy Assigned" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, const std::string& s) {
    if (i >= 0 && i < 100) ideas[i] = s;
}

std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 100) return ideas[i];
    return "";
}

