#include "deck.h"
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>

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
    a.add_card("A method that changes the value of a private variable","Setter ");
    
    a.add_false_answer("Base class");
    a.add_false_answer("Override");
    a.add_false_answer("Namespace");
    
    Card card0{"Reuse and extension of fields and method implementation from another class","Inheritance"};
    Card card1{" A data type that can typically be handled directly by the underlying hardware","Primitive type"};
    Card card2{"A data type consisting of a fixed set of constant values called enumerators","Enumerated type"};
    Card card3{"A template encapsulating data and code that manipulates it","Class"};
    Card card4{"An encapsulated bundle of data and code","Instance"};
    Card card5{"An instance of a class containing a set of encapsulated data and associated methods","Object"};
    Card card6{"A block of memory associated with a symbolic name that contains an object instance or aprimitive data value","Variable"};
    Card card7{"A short string representing a mathematical, logical, or machine control action","Operator"};
    Card card8{"A method that returns the value of a private variable","Getter"};
    Card card9{"A method that changes the value of a private variable","Setter "};
    
        cards.push_back(card0);
        cards.push_back(card1);
        cards.push_back(card2);
        cards.push_back(card3);
        cards.push_back(card4);
        cards.push_back(card5);
        cards.push_back(card6);
        cards.push_back(card7);
        cards.push_back(card8);
        cards.push_back(card9);
        
    std::cout << "Select the number of term for each defination (-1 to exit)\n" << std::endl;
    ans=a.options();

    
    while(true){
    for(int j=0;j<ans.size();j++){
        std::cout << j << ") " << ans[j] <<std::endl;
    }
    
    std::cout << "" << std::endl;
    srand(time(0));
    random_number=(rand()%9);
    std::cout << cards[random_number];
    std::cin >> input;
    
    if(stoi(input)==-1){
        break;
        }
               
    std::string response=cards[random_number].attempt(input);
    std::cout << response << std::endl;
    std::cout << "" << std::endl;
    }
    
    
    
    return 0;
    
    }

