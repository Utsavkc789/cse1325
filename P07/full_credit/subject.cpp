#include "subject.h"

std::ostream& operator<<(std::ostream& ost, Suject subject){
        ost << subject.to_string;
        return ost;
        }


std::string to_string(Subject subject){
        std::vector<std::string> v= {"Reading", "Writing", "Math", "Science" , "History", "Art", "Musicsports"};
        return v[subject];
        }
        
std::string load_subject(std::istream& ist,Subject subject){
        std::string input;
        ist >> input;
        return input.to_string();
        }
