#include <iostream>
#include <string>

using namespace std;

int main(){
    string user_input;
    cout << "Enter your name ,Please:\n";
    getline(std::cin,user_input);
    
    cout << "Hello " <<user_input<<"." <<" Thank You!\n";
    return 0;
    
}
