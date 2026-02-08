#include "Animal.hpp"
#include "Brain.hpp"
#include "ShallowDog.hpp"
#include <iostream>

ShallowDog::ShallowDog()
{
    type = "ShallowDog";
    std::cout << "Default constructor called for ShallowDog" << std::endl;
    brain = new Brain();
}

ShallowDog::ShallowDog(const ShallowDog& other) : Animal(other)  
{
    std::cout << "Copy constructor called for ShallowDog" << std::endl;
    brain = other.brain;
}

ShallowDog& ShallowDog::operator=(const ShallowDog& other) //burada delete brain yapmalı mıyım ? pointerlar öncesinde paylaşılmıyorsa olabilir. Eğer pointer’lar zaten paylaşılıyorsa patlamayı erkene çekmiş oluruz: delete brain → diğer nesnenin pointer’ı anında dangling, eğer copy assignment operator içindeyken paylaşılmıyorsa destruct zamanında patlar erkene çekilme olmaz.
{
    std::cout << "Copy assignment operator called for ShallowDog" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = other.brain;
    }
    return *this;
}

ShallowDog::~ShallowDog()
{
    delete brain;
    std::cout << "Destructor called for ShallowDog" << std::endl;
}

void ShallowDog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

std::string ShallowDog::getIdea(int index) const
{
    return (brain->getIdea(index));
}

void ShallowDog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}