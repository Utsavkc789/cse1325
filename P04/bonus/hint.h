#ifndef _HINT_H
#define _HINT_H_

#include <string>
#include <iostream>

class Hintcard: public Card{
    
    private:
    std::string _hint;
    
    public:
    Hintcard(std::string question,std::string answer,std::string hint):Card::Card(question,answer),_hint{hint}{}
    virtual std::string attempt(std::string response) override;
 
    };
    
#endif
