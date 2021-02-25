#include "card.h"
#include <cstring>

std::string Card::attempt(std::string response){
    
    if(this->_answer==response){
        return "Correct!";
        }
         
    for(int i=0;i<this->_answer.size();i++){
        this->_answer[i]=toupper(this->_answer[i]);
        }
        
    return "X - Correct answer was "+this->_answer+"."+"\n";

}

std::ostream& operator<<(std::ostream& ost,Card& m){
    ost << m._question <<"? ";
    return ost;
    }
    
    
    
    
    
