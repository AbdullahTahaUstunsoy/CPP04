#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

//Animal'ın destructorunda virtual kullanılmadığında animalın silinip dog ve cat'in memory leak oluşturduğunu göster.
int main()
{
    int i = 0;
    std::cout << "Creating animals..." << std::endl;
    const Animal* animals[4];
    while(i < 2)
        animals[i++] = new Dog();
    while(i < 4)
        animals[i++] = new Cat();

    i = 0;
    std::cout << "Making sounds..." << std::endl; //
    while(i < 4) 
        animals[i]->makeSound();
    i = 0;
    std::cout << "Deleting animals..." << std::endl;
    while(i < 4)
        delete animals[i++];



        
    return (0);
}