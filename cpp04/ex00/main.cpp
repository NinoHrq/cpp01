#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
return 0;
};


// int main() {
//     std::cout << "=== Test Animal/Dog/Cat (avec virtual) ===" << std::endl;
//     const Animal* a = new Animal();
//     const Animal* d = new Dog();
//     const Animal* c = new Cat();

//     std::cout << "Type a: " << a->getType() << std::endl;
//     std::cout << "Type d: " << d->getType() << std::endl;
//     std::cout << "Type c: " << c->getType() << std::endl;

//     a->makeSound(); 
//     d->makeSound();
//     c->makeSound();

//     delete a;
//     delete d;
//     delete c;

//     std::cout << "\n=== Test WrongAnimal/WrongCat (sans virtual) ===" << std::endl;
//     const WrongAnimal* wa = new WrongAnimal();
//     const WrongAnimal* wc = new WrongCat();

//     std::cout << "Type wa: " << wa->getType() << std::endl;
//     std::cout << "Type wc: " << wc->getType() << std::endl;

//     wa->makeSound();
//     wc->makeSound();

//     delete wa;
//     delete wc;

//     std::cout << "\n=== Test direct WrongCat ===" << std::endl;
//     WrongCat realWC;
//     realWC.makeSound();

//     return 0;
// };

