
#include "grade.h"
#include <iostream>

std::ostream& operator<<(std::ostream& ost, const Grade& semester) {
    ost << ((grade == Grade::A) ? "A" :
           (grade == Grade::B) ? "B" : 
           (grade == Grade::C) ? "C" : 
           (grade == Grade::D) ? "D" : 
           (grade == Grade::F) ? "F" : 
           (grade == Grade::X) ? "In progress" : 
           "Incomplete");
    return ost;
}

Grade load_grade(std::istream& ist) {
    std::string s;
    std::getline(ist, s);
    if(s == "A") return Grade::A;
    if(s == "B") return Grade::B;
    if(s == "C") return Grade::C;
    if(s == "D") return Grade::D;
    if(s == "F") return Grade::F;
    if(s == "I") return Grade::I;
    if(s == "X") return Grade::X;
    throw std::runtime_error{std::string{"Invalid Grade: " + s}};
}

