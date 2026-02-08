#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "ShallowDog.hpp"
#include <iostream>

//Animal'ın destructorunda virtual kullanılmadığında animalın silinip dog ve cat'in memory leak oluşturduğunu göster.
int main()
{
    int i = 0;
    std::cout << BLUE << "Creating animals..."<< RESET << std::endl;
    const Animal* animals[4];  //bu kısmı stackte olusturamayız. Polymorphism C++98’de pointer veya reference ister. Animal animals[4]; animals[0] = Dog(); olsaydı slicing olurdu yani sadece Animal kısmı kopyalanırdı, Dog kısmı kaybolurdu. Bu yüzden pointer kullanıyoruz.
    while(i < 2)
        animals[i++] = new Dog();
    while(i < 4)
        animals[i++] = new Cat();
    
    std::cout << "---------------------------------" << std::endl;
    
    i = 0;
    std::cout << BLUE << "Making sounds..." << RESET << std::endl;
    
    while(i < 4) 
        animals[i++]->makeSound();
    
    std::cout << "---------------------------------" << std::endl;
    
    i = 0;
    std::cout << BLUE << "Deleting animals..." << RESET << std::endl;
    while(i < 4)
        delete animals[i++];
    std::cout << "---------------------------------" << std::endl;
    
    std::cout << BLUE << "Deep copy test for Dog using the copy constructor" << RESET << std::endl;
    Dog dog1; //dog olusunca brain'i de olustu
    dog1.setIdea(0, "I want some steak!");
    Dog dog2(dog1); //copy constructor ile dog1'in brain'ini kopyaladı
    dog2.setIdea(0, "I want some bones!"); //dog2'nin brain'inde ideas'ın 0. indexi değişti ama dog1'in brain'inde ideas'ın 0. indexi değişmedi
    std::cout << "Dog1's idea: " << dog1.getIdea(0) << std::endl; //dog1'in brain'inde 0. indexi yazdır
    std::cout << "Dog2's idea: " << dog2.getIdea(0) << std::endl; //dog2'nin brain'inde 0. indexi yazdır
    
    std::cout << "---------------------------------" << std::endl;

    std::cout << BLUE << "Deep copy test for Cat using the copy constructor" << RESET << std::endl;
    Cat cat1;
    cat1.setIdea(0, "I want some fish!");
    Cat cat2;
    cat2 = cat1; //copy assignment operator ile cat1'in brain'ini kopyaladı
    cat2.setIdea(0, "I want some milk!");
    std::cout << "Cat1's idea: " << cat1.getIdea(0) << std::endl; //cat1'in brain'inde ideas'ın 0. indexini yazdır
    std::cout << "Cat2's idea: " << cat2.getIdea(0) << std::endl; //cat2'nin brain'inde ideas'ın 0. indexini yazdır

    std::cout << "---------------------------------" << std::endl;


    /*
    std::cout << BLUE << "Testing Shallow Copy" << RESET << std::endl; //bu testi çalıştırınca core dumped olduğu için yoruma aldım

    ShallowDog shallowDog1;
    shallowDog1.setIdea(0, "I want some steak!");
    ShallowDog shallowDog2(shallowDog1); //copy constructor ile shallowDog1'in brain'ini kopyaladı
    shallowDog2.setIdea(0, "I want some bones!");
    std::cout << "ShallowDog1's idea: " << shallowDog1.getIdea(0) << std::endl; //shallowDog1'in brain'inde 0. indexi yazdır
    std::cout << "ShallowDog2's idea: " << shallowDog2.getIdea(0) << std::endl; //shallowDog2'nin brain'inde 0. indexi yazdır
    */ 
    
    
    std::cout << "---------------------------------" << std::endl;

    std::cout << BLUE << "Incorrect polymorphism implementation" << RESET << std::endl;
    WrongAnimal* wrongAnimal = new WrongCat();
    wrongAnimal->makeSound();
    delete wrongAnimal;

    return (0);
}