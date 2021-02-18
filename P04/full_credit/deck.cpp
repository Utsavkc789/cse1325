#include "deck.h"

void Deck::add_card(std::string question,std::string answer){
       Card c{question,answer};
       _cards.push_back(c);
       _options.push_back(answer);    
    
}

void Deck::add_false_answer(std::string false_answer){
    _options.push_back(false_answer);
}


std::vector<std::string> Deck::options(){
    return _options;
    } 





