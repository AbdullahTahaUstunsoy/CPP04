#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "----- Correct implementation test: Testing Animal, Cat, and Dog -----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    std::cout << meta->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound();
    j->makeSound();

    delete meta;
    delete i;
    delete j;

    std::cout << "----- Wrong implementation test: WrongAnimal and WrongCat -----" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    std::cout << wrongMeta->getType() << " " << std::endl;
    std::cout << wrongI->getType() << " " << std::endl;
    wrongMeta->makeSound();
    wrongI->makeSound();

    delete wrongMeta;
    delete wrongI;

    return (0);
}