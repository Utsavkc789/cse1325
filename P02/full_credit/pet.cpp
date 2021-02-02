#include "pet.h"


std::string to_string(animal Animal)
{

    switch (Animal)
    {

    case DOG:
        return "Dog";
    case CAT:
        return "Cat";
    case RABBIT:
        return "Rabbit";
    case HORSE:
        return "Horse";
    }

    return "Wrong animal";
}


std::string to_name(string a)
{
    switch (a)
    {

    case BRUNO:
        return "Bruno";
    case STINKY:
        return "Stinky";
    case BOB:
        return "Bob";
    case FAST:
        return "Fast";
    }
    return "No such name";
}

    
    Pet::Pet(string name, animal Animal, double age)
    {
        this->name = name;
        this->Animal = Animal;
        this->age = age;
        std::string to_string();
    }

    std::string Pet::to_string()
    {
        return ::to_name(name) + " is a " + ::to_string(Animal) + " age " + std::to_string(age)+"."+ "\n";
    } 
