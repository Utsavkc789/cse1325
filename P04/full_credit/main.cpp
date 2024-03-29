#include "deck.h"
#include <cstring>
#include <vector>
#include <cstdlib>


int main() {
    int random_number;
    std::vector<Card>cards;
    std::vector<std::string>ans;
    std::string input;
    Deck a;
    
    a.add_card("Reuse and extension of fields and method implementation from another class","Inheritance");
    a.add_card(" A data type that can typically be handled directly by the underlying hardware","Primitive type");
    a.add_card("A data type consisting of a fixed set of constant values called enumerators","Enumerated type");
    a.add_card("A template encapsulating data and code that manipulates it","Class");
    a.add_card("An encapsulated bundle of data and code","Instance");
    a.add_card("An instance of a class containing a set of encapsulated data and associated methods","Object");
    a.add_card("A block of memory associated with a symbolic name that contains an object instance or aprimitive data value","Variable");
    a.add_card("A short string representing a mathematical, logical, or machine control action","Operator");
    a.add_card("A method that returns the value of a private variable","Getter");
    a.add_card("A method that changes the value of a private variable","Setter");
    
    a.add_false_answer("Base class");
    a.add_false_answer("Override");
    a.add_false_answer("Namespace");
    
    Card _card={"",""};
        
    std::cout << "Select the number of term for each defination (-1 to exit)\n" << std::endl;
    ans=a.options();
    
    while(true){
    for(int j=0;j<ans.size();j++){
        std::cout << j << ") " << ans[j] <<std::endl;
    }
    
    std::cout << "" << std::endl;
    _card=a.deal();
    std::cout << _card;
    std::cin >> input;
    
    if(stoi(input)==-1){
        break;
        }
               
    std::string response=_card.attempt(ans[stoi(input)]);
    std::cout << response << std::endl;
    std::cout << "" << std::endl;
    }
    
    return 0;
    }
    
    
    
    
    
    

