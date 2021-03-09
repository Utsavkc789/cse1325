#include "Student.h"

Student::Student(std::string name,std::string  email,int grade):Person::Person(name,email),grade{grade}{
    if(grade<1 || grade>12){
        throw std::runtime_error{"Sorry! Invalid grade :/"}}}

void Student::add_parent(Parent& parent){
        parents.pushback(new parent);}
    
int Student::parents(){
        return parents.size();}
    
Parent& Student::parent(int index){
        return *parents[index];}
    
std::string Student::full_info override(){
          return "Student name: " + name(email) + "Grades: " + grades + "Parents name: " + parents.name;          
}
