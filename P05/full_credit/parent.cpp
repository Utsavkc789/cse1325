include "parent.h"

Parent(std::string name,std::string email): Person(name,email){}

void Parent::add_student(Student& student){
       _students.push(new student);}
        
int Parent::students(){ 
    return _students.size();}
        

Student& Parent::student(int index){
    return *_students[index];}

std::string Parent::full_info const(){
    return "Parent name: " + _name(_email) + "Student name: " + _students._name(_students._email);}
        
