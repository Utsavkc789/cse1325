#ifndef __STUDENT_H
#define __STUDENT_H

#include "person.h"
#include <vector>
#include <map>


class Parent;

class Student : public Person {
  
  protected:
    int _grade; 
    typedef std::vector<Parent*> Parents;
    Parents _parents;
  
  
  public:
    Student(std::string name, std::string email, int grade);
    Student(std::istream& ist);
    void save(std::ostream& ost) override;
    void save_aggregates(std::ostream& ost);
    void load_aggregates(std::istream& ist, const std::map<std::string, Parent*>& parents);
    void add_parent(Parent& parent);
    std::string full_info() const override;
    typedef Parents::iterator iterator;
    typedef Parents::const_iterator const_iterator;
    iterator begin() {return _parents.begin();}
    iterator end() {return _parents.end();}
     
  
};

#endif
