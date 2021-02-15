#include "card.h"

std::string Card::attempt(std::string response){
    int input=stoi(response);
    return "ABC";
    
}

std::ostream& operator<<(std::ostream& ost,Card& m){
    ost << m._answer << std::endl;
    return ost;
}




