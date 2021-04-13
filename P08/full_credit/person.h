#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <fstream> 

class Person {
  public:
    Person(std::string name, std::string email);
    std::string to_string() const;
    Person(std::istream& ist);
    virtual void save(std::ostream& ost);
    virtual std::string full_info() const;
    friend std::ostream& operator<<(std::ostream& ost, const Person& person);
  protected:
    std::string _name;
    std::string _email;
};

#endif
