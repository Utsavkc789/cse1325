#include "parent.h"
#include "student.h"

void Parent::add_student(Student& student) {
    _students.push_back(&student);
}
int Parent::students() {return _students.size();}
Student& Parent::student(int index) {
    return *(_students.at(index));
}
std::string Parent::full_info() const {
    std::string info = Person::full_info() + " - Students: ";
    std::string separator;
    for(auto s : _students) {
        info += separator + s->to_string();
        separator = ", ";
    }
    return info;
}
void Parent::save(std::ostream& ost){ ost << _name << '\n' << _email << std::endl; }
Parent::Parent(std::istream& ist):Person(ist){ }
