#ifndef __PARENT_H
#define __PARENT_H


#include <iostream>
#include <string>
#include <vector>
#include "person.h"

class Student;

class Parent: public Person{
    protected:
        std::vector<Student*> _students;
        
    public:
        Parent(std::string name,std::string email);
        void add_student(Student& student);
        int students();
        Student& student(int index);
        std::string full_info() const override;
        };




#endif
