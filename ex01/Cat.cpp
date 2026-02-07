#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    type = "Cat";
    std::cout << "Default constructor called for Cat" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator called for Cat" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructor called for Cat" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}