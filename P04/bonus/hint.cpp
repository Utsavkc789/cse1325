 #include "hint.h"
 
std::string attempt(std::string response){
        if(this->_answer==response){
        return "Correct!";
        }
         
        else {
        return "X - Hint :"+this->_hint+"."+"\n";
        }
        }
