#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    std::cout << "=== Base polymorphisme + dtor virtuel ===\n";
    const Animal* a1 = new Dog();
    const Animal* a2 = new Cat();
    a1->makeSound();
    a2->makeSound();
    delete a1;
    delete a2;

    std::cout << "\n=== Deep copy: constructeur de copie ===\n";
    Dog d1;
    d1.setIdea(0, "Chase the ball");
    d1.setIdea(1, "Nap time");

    Dog d2 = d1; // copy-ctor (deep copy)
    d2.setIdea(0, "Guard the house");

    std::cout << "d1 idea[0] = " << d1.getIdea(0) << "\n"; // doit rester "Chase the ball"
    std::cout << "d2 idea[0] = " << d2.getIdea(0) << "\n"; // "Guard the house"

    std::cout << "\n=== Deep copy: operateur d’affectation ===\n";
    Dog d3;
    d3 = d1; // operator=
    d3.setIdea(1, "Eat treats");

    std::cout << "d1 idea[1] = " << d1.getIdea(1) << "\n"; // "Nap time"
    std::cout << "d3 idea[1] = " << d3.getIdea(1) << "\n"; // "Eat treats"

    std::cout << "\n=== Tableau polymorphe ===\n";
    const int N = 6;
    Animal* zoo[N];
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) zoo[i] = new Dog();
        else            zoo[i] = new Cat();
    }
    for (int i = 0; i < N; ++i) zoo[i]->makeSound();
    for (int i = 0; i < N; ++i) delete zoo[i];

    return 0;
}

// #include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"
// #include <iostream>

// int main() {
//     std::cout << "=== Création d’animaux ===" << std::endl;
//     const Animal* dog = new Dog();
//     const Animal* cat = new Cat();

//     std::cout << "\n=== Sons ===" << std::endl;
//     dog->makeSound();
//     cat->makeSound();

//     std::cout << "\n=== Destruction ===" << std::endl;
//     delete dog;
//     delete cat;

//     return 0;
// }


