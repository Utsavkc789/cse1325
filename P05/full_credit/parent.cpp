include "parent.h"

Parent(std::string name,std::string email):Person::Person(name,email){}

void Parent::add_student(Student& student){
       students.push(new student);}
        
int Parent::students(){ 
    return students.size();}
        

Student& Parent::student(int index){
    return *students[index];}

std::string Parent::full_info const(){
    return "Parent name: " + name(email) + "Student name: " + students.name(students.email);}
        
