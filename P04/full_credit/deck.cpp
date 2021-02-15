#include "deck.h"

void Deck::add_card(std::string question,std::string answer){
        Card c1={question,answer};
        _cards.push_back(c1);
        _options.push_back(answer);
    
}

void Deck::add_false_answer(std::string false_answer){
     std::string ans="Friend";
     std::string ans1="Override";
     std::string ans2="Attribute";
     
    _options.push_back(ans);
    _options.push_back(ans1);
    _options.push_back(ans2);
}


std::vector<std::string> Deck::options(){

    return _options;
    
    }
