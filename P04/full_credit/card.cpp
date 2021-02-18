#include "card.h"
#include <cstring>

std::string Card::attempt(std::string response){
    int _response=stoi(response);
    switch(_response){
    
    case 0:
    if(this->_answer=="Inheritance"){
          return "Correct!";}
          
    case 1:
    if(this->_answer=="Primitive type"){
          return "Correct!";}
    
    case 2:
    if(this->_answer=="Enumerated type"){
          return "Correct!";}
    
    case 3:
    if(this->_answer=="Class"){
          return "Correct!";}
    
    case 4:
    if(this->_answer=="Instance"){
          return "Correct!";}
    
    case 5:
    if(this->_answer=="Object"){
          return "Correct!";}
    
    case 6:
    if(this->_answer=="Variable"){
          return "Correct!";}
    
    case 7:
    if(this->_answer=="Operator"){
          return "Correct!";}     
    
    
    case 8:
    if(this->_answer=="Getter"){
          return "Correct!";}     
    
    
    case 9:
    if(this->_answer=="Setter"){
          return "Correct!";}     
    }
    
    return "X - Correct answer was "+this->_answer +"."+"\n";

}


std::ostream& operator<<(std::ostream& ost,Card& m){
    
    ost << m._question <<"? ";
    
    return ost;
}


