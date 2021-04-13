#include "Course.h"

Course(Subject subject, int grade):_subject{subject},_grade{grade}{}

Course(std::istream& ist){
          ist >> _subject;
          ist >> _grade;
          ist.ignore(32767, '\n');

}
        
void save(std::ostream& ost){
        ost << _subject << '\n' << _grade << '\n';
}


std::ostream& operator<<(std::ostream& ost, Course& course){
    ost << _subject << "( grade " << _grade << ")" ;   
    return ost;
}
