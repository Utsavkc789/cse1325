#include "semester.h"

std::to_string(Semester semester){
    std::vector<std::string> s= { "Fall", "Spring", "Summer"};
    return s[semester];
    }
    
std::ostream& operator<<(std::ostream& ost, Semester semester){
        ost << semester.to_string();
        return ost;
        }
        
std::string load_subject(std::istream& ist){
       std::string input;
       ist >> input;
       return input.to_string(); 
       }
