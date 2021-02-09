 #ifndef __FRACTION_H
 #define __FRACTION_H

#include <iostream>
#include <limits>
 
class Fraction
{
private:
    int _numerator{};
    int _denominator{};
 
public:
    Fraction(int numerator = 0, int denominator = 1) :
        _numerator{ numerator }, _denominator{ denominator }
    {
     
        reduce();
    }
 
    static int GCD(int n, int d)
    {
        return d == 0 ? n : GCD(d, n % d);
    }
 
    void reduce()
    {
        if (_numerator != 0 && _denominator != 0)
        {   
            if(_denominator<0){
                _numerator=-_numerator;
                _denominator=-_denominator;
                int GCD{ Fraction::GCD(_numerator, _denominator) };
                _numerator /= GCD;
                _denominator /= GCD;
        }
    }
    }
    
    
    Fraction operator-();
    Fraction operator/(const Fraction& rhs);
    Fraction operator-(const Fraction& rhs);
    Fraction operator*(const Fraction& rhs);
    Fraction operator+(const Fraction& rhs);
    friend Fraction operator*(const Fraction& rhs, int value);
    friend Fraction operator*(int value, const Fraction& rhs);
    friend std::istream& operator >> (std::istream& in, Fraction& m);
    friend std::ostream& operator << (std::ostream& output, const Fraction& m);
    friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
 
};
#endif
