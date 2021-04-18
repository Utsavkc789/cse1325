#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade)
  :  Person(name, email), _grade{grade} { }
Student::Student(std::istream& ist) : Person(ist) {
    ist >> _grade; ist.ignore(32767, '\n');
}
void Student::save(std::ostream& ost) {
    Person::save(ost);
    ost << _grade << '\n';
}
void Student::save_aggregates(std::ostream& ost) {
    ost << _email << '\n';
    ost << _parents.size() << '\n';
    for(Parent* parent : _parents) ost << *parent << '\n';
}
void Student::load_aggregates(std::istream& ist, const std::map<std::string, Parent*>& parents) {
    std::string email;
    std::getline(ist, email);
    if(email != _email) 
        throw std::runtime_error{"load_aggregates: " + email + " vs " + _email};
    
    int size;
    ist >> size; ist.ignore(32767, '\n');
    if(size > 100) throw std::runtime_error{"Aggregate parents too big"};
    while(size--) {
        std::getline(ist, email); 
        if(!ist) throw std::runtime_error{"Input stream failed on student aggregate load"};
        add_parent(*parents.at(email));
    }
}

void Student::add_parent(Parent& parent) {
    for(Parent* p : _parents) if(p == &parent) return;
    _parents.push_back(&parent);
}

std::string Student::full_info() const {
    std::string info = Person::full_info() + " in grade " + std::to_string(_grade) + " - Parents: ";
    for(Parent* p : _parents) std::cout << *p << ' ';
    return info;
}
