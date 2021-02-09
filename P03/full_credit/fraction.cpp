#include "fraction.h"
 
 Fraction Fraction::operator-()
{
    return Fraction{-this->_numerator,this->_denominator};
} 
 
Fraction Fraction::operator*(const Fraction& rhs)
{
    return Fraction(this->_numerator * rhs._numerator, this->_denominator * rhs._denominator);
}
 
Fraction operator*(const Fraction& f1, int value)
{
    return Fraction(f1._numerator * value, f1._denominator);
}
 
Fraction operator*(int value, const Fraction& f1)
{
    return Fraction(f1._numerator * value, f1._denominator);
}

Fraction Fraction::operator+(const Fraction& rhs){
    return{this->_numerator*rhs._denominator+rhs._numerator*this->_denominator,this->_denominator*rhs._denominator};
}

Fraction Fraction::operator-(const Fraction& rhs){
    return{this->_numerator*rhs._denominator-rhs._numerator*this->_denominator,this->_denominator*rhs._denominator};
}

Fraction Fraction::operator/(const Fraction& rhs){
    return{this->_numerator*rhs._denominator,this->_denominator*rhs._numerator};
}

bool operator!=(const Fraction& lhs, const Fraction& rhs){
    if(lhs._numerator==rhs._numerator && lhs._denominator==rhs._denominator){
         return true;
         }
    else{
        return false;
        }
} 

std::istream& operator >> (std::istream& ist, Fraction &m)
{
    //std::regex integer{"-?\\d+/-?\\d+"};
    //if(std::regex_match(ist,integer)){
    ist >> m._numerator;
    ist.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    ist >> m._denominator;
    //}
    
    //else{
    //throw std::runtime_error{"Bad Fraction read"};
    //}
    
    return ist;
}
 

std::ostream& operator << (std::ostream& ost, const Fraction& m)
{
    ost << m._numerator << '/' << m._denominator;
 
    return ost;
}
 

