
#include "person.h"

Person::Person(std::string name,std::string email):_name{name},_email{email}{}

std::string Person::to_string(){
        return _name;}
    
std::string Person::full_info() const{
        return _name + "(" +_email + ")";}

std::ostream& Person::operator<<(std::ostream& ost,const Person& person){
        ost << person._name;
        return ost;}






