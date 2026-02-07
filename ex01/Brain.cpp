#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy constructor called for Brain" << std::endl;
    int i = -1;
    int j = other.ideas->length();
    while(++i < j)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy assignment operator called for Brain" << std::endl;
    if (this != &other)
    {
        int i = -1;
        int j = other.ideas->length();
        while(++i < j)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor called for Brain" << std::endl;
}