#include "deck.h"
#include <ctime>
#include <cstdlib>
#include <cstring>

void Deck::add_card(std::string question,std::string answer,std::string hint){
       if(hint.empty()){
        _cards.push_back(new Card{question,answer});
       }
       _cards.push_back(new Hintcard{question,answer,hint}); 
}

void Deck::add_false_answer(std::string false_answer){
    _options.push_back(false_answer);
}


std::vector<std::string> Deck::options(){
    return _options;
    } 

Card* Deck::deal(){
    
    if(_cards.empty()){
        throw std::runtime_error{"No card was added!"};
        }
        
   else{
       if(_next_card<9){
            _next_card=_next_card+1;
            return _cards[_next_card];
            }
       
       else{
            Card temp{"",""};
            int random_number=rand()%_cards.size();
                 return _cards[random_number];
            }
       }
       }
       
     
            
            
            
            
