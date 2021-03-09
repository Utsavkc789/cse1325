#include "student.h"

Student::Student(std::string name,std::string email,int grade): Person(name,email),_grade{grade}{
    if(grade<1 || grade>12){
        throw std::runtime_error{"Sorry! Invalid grade :/"};}}

void Student::add_parent(Parent& parent){
        _parents.push_back(&parent);}
    
int Student::parents(){
        return _parents.size();}
    
Parent& Student::parent(int index){
        return *_parents[index];}
    
std::string Student::full_info() const{
          return "Student name: " + _name + " ( " + _email + " ) , Grades: " + std::to_string(_grade);}
