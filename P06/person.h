
#ifndef __PERSON_H
#define __PERSON_H


#include <string>
#include <ostream>


class Person{
    
    protected:
        std::string _name;
        std::string _email;
        
    public:
        Person(std::string name,std::string email);
        std::string to_string();
        virtual std::string full_info() const;
        friend std::ostream& operator<<(std::ostream& ost, const Person& person);
        };
        
#endif
        
        
            
