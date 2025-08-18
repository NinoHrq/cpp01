#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include<iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* brain;
    public:
        Dog();
        virtual ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        virtual void makeSound() const;
        void        setIdea(int i, const std::string& s);
std::string getIdea(int i) const;
     
};

#endif