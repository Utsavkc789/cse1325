#ifndef __PET_H
#define __PET_H

#include <iostream>
#include <vector>

enum animal
{
    DOG,
    CAT,
    RABBIT,
    HORSE
};

std::string to_string(animal Animal);

enum string
{
    BRUNO,
    STINKY,
    BOB,
    FAST
};

std::string to_name(string a);

class Pet
{
    string name;
    animal Animal;
    double age;

public:
    Pet(string name, animal Animal, double age);
    std::string to_string();
    double human_year(animal Animal,double age);
};



#endif


