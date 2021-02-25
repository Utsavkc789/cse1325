#ifndef _CARD_H
#define _CARD_H_

#include <iostream>
#include <vector>
#include <string>


class Card{
    protected:
    std::string _question;
    std::string _answer;
    
    public:
    Card(std::string question,std::string answer):_question{question},_answer{answer}{}
    virtual std::string attempt(std::string response);
    friend std::ostream& operator<<(std::ostream& ost,Card& m);
};

#endif

