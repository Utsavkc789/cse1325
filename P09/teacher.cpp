
#include "teacher.h"
#include <iostream>

Teacher::Teacher(std::string name, std::string email):Person(name,email){}
Teacher::Teacher(std::istream& ist):Person(ist){
           ist.ignore(32767, '\n');
           }
void Teacher::save(std::ostream& ost){
       Person::save(ost);
        }
std::string Teacher::full_info() const{
       std::string output = Person::full_info();
       return output;
       }
