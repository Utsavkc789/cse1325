#include "fraction.h"

int main()
{   
    Fraction f1{};
    Fraction f2{};
    std::cout << "Enter two fractions (n/d n/d): ";
    std::cin >> f1 >> f2;
    std::cout << "negative " << f1 << " = " << -f1 << std::endl; 
    std::cout << "negative " << f2 << " = " << -f2 << std::endl; 
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl; 
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl; 
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl; 
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl; 
    std::cout << f1 << " != " << f2 << std::endl ;
    return 0;
}
