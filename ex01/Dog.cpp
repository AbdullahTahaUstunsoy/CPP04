#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
    std::cout << "Default constructor called for Dog" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)  
{
    std::cout << "Copy constructor called for Dog" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator called for Dog" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain; // eski Brain’i sil
        brain = new Brain(*other.brain); // yenisini Brain oluştur
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor called for Dog" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}