#ifndef SHALLOWDOG_HPP
#define SHALLOWDOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class ShallowDog : public Animal
{
    private:
        Brain *brain;
    public:
        ShallowDog();
        ShallowDog(const ShallowDog& other);
        ShallowDog& operator=(const ShallowDog& other);
        ~ShallowDog();
        void makeSound() const;
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};

#endif