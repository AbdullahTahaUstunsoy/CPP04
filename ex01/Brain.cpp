#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy constructor called for Brain" << std::endl;
    int i = 0;
    while(i < 100)
    {
        ideas[i] = other.ideas[i];
        i++;
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy assignment operator called for Brain" << std::endl;
    if (this != &other)
    {
        int i = 0;
        while(i < 100)
        {
            ideas[i] = other.ideas[i]; //Shallow copy gibi gözüküyor ama aslında deep copy yapılıyor.
            i++;
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor called for Brain" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}