#include "person.h"

Person::Person(std::string name, std::string email)
  :  _name{name}, _email{email} { }
std::string Person::to_string() const {return _name;}
std::string Person::full_info() const {return _name + " (" + _email + ")";}
std::ostream& operator<<(std::ostream& ost, const Person& person) {
    ost << person.to_string();
    return ost;
}
Person::Person(std::istream& ist){ 
        std::getline(ist, _name);
        ist >> _email;
        ist.ignore(32767,'\n');
        }
void Person::save(std::ostream& ost){ ost << _name << '\n' <<_email << std::endl;}
