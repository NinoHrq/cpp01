#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include<iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* brain;
    public:
        Cat();
        virtual ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual void makeSound() const;
        void        setIdea(int i, const std::string& s);
std::string getIdea(int i) const;

};

#endif