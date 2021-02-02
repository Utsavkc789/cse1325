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
    }
    
    double Pet::human_year(animal Animal,double age){
        
        switch(Animal)
        {
        case DOG:
            return age*15;
        case CAT:
            return age*15;
        case RABBIT:
            return age*7.5;
        case HORSE:
            return age*6.5;
            
        }
        
        return 0;
        
    }

    std::string Pet::to_string()
    {
        return ::to_name(name) + " is a " + ::to_string(Animal) + " age " + std::to_string(age) +" or "+std::to_string(Pet::human_year(Animal,age))+" in human-equivalent years." +"\n";
    } 
