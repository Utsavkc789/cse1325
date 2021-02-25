#include <iostream>
#include <vector>
#include <string>
#include "card.h"

class Deck{
    
    private:
    std::vector<Card>_cards;
    std::vector<std::string>_options;
    int _next_card;
    
    public:
    void add_card(std::string question,std::string answer);
    void add_false_answer(std::string false_answer);
    std::vector<std::string> options();
    Card deal();
    
};
