#include "deck.h"
#include <cstring>

void  print_output(std::vector<std::string>_options){
        for(int i=0;i<_options.size();i++){
                std::cout << _options[i] << std::endl;
}
}

int main() {
    std::vector<Card>cards;
    std::vector<std::string>ans;
    Deck a;
    std::string input;
    Card card1{"Reuse and extension of fields and method implementation from another class","Inheritance"};
    Card card2{" A data type that can typically be handled directly by the underlying hardware","Primitive type"};
    Card card3{"A data type consisting of a fixed set of constant values called enumerators","Enumerated type"};
    Card card4{"A template encapsulating data and code that manipulates it","Class"};
    Card card5{"An encapsulated bundle of data and code","Instance"};
    Card card6{"An instance of a class containing a set of encapsulated data and associated methods","Object"};
    Card card7{"A block of memory associated with a symbolic name that contains an object instance or aprimitive data value","Variable"};
    Card card8{"A short string representing a mathematical, logical, or machine control action","Operator"};
    
        cards.push_back(card1);
        cards.push_back(card2);
        cards.push_back(card3);
        cards.push_back(card4);
        cards.push_back(card5);
        cards.push_back(card6);
        cards.push_back(card7);
        cards.push_back(card8);
        
    std::cout << "Select the number of term for each defination (-1 to exit)\n" << std::endl;
    a={"",a.options()};
    
    for(int i=0;i<a.options().size();i++){
    std::cout << a[i]._options << std::endl;
    }
    print_output(ans);

    std::cin >> input;
    
    
    
    return 0;
}
