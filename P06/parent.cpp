#include "parent.h"
#include <string>
#include "student.h"

Parent::Parent(std::string name,std::string email): Person(name,email){}

void Parent::add_student(Student& student){
       _students.push_back(&student);}
        
int Parent::students(){ 
    return _students.size();}
        

Student& Parent::student(int index){
    return *_students[index];}

std::string Parent::full_info() const{
    std::string info = "Parent name: " + _name + " ( " + _email + " ) " + "Student: ";
    std::string _separator;
    
    for(auto s:_students){
           info += _separator + s->to_string();
           _separator=", ";
           }
    return info;
    }    
