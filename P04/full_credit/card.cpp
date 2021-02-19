#include "card.h"
#include <cstring>

std::string Card::attempt(std::string response){
    int _response=stoi(response);
    
    if(_response==0){
    if(this->_answer=="Inheritance"){
          return "Correct!";}
         }
         
    if(_response==1){     
    if(this->_answer=="Primitive type"){
          return "Correct!";}
         }
    
    if(_response==2){
    if(this->_answer=="Enumerated type"){
          return "Correct!";}
         }
    
    if(_response==3){
    if(this->_answer=="Class"){
          return "Correct!";}
         }
    
    if(_response==4){
    if(this->_answer=="Instance"){
          return "Correct!";}
         }
    
    if(_response==5){
    if(this->_answer=="Object"){
          return "Correct!";}
         }
    
    if(_response==6){
    if(this->_answer=="Variable"){
          return "Correct!";}
         }
   
    if(_response==7){
    if(this->_answer=="Operator"){
          return "Correct!";}
         }    
    
    
    if(_response==8){
    if(this->_answer=="Getter"){
          return "Correct!";}
         }    
    
    
    if(_response==9){
    if(this->_answer=="Setter"){
          return "Correct!";}
         }
         
    for(int i=0;i<this->_answer.size();i++){
        this->_answer[i]=toupper(this->_answer[i]);
        }
        
    return "X - Correct answer was "+this->_answer +"."+"\n";
       
 
}

std::ostream& operator<<(std::ostream& ost,Card& m){
    ost << m._question <<"? ";
    return ost;
    }
    
    
    
    
    
