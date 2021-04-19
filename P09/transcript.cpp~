
#include "transcript.h"

Transcript::Transcript(Student& student, Section& section):_student{student},_section(section){}

Transcript::Transcript(std::istream& ist):_student{ist},_section{ist}{
    ist.ignore(32767, '\n');
    }

void Transcript::assign_grade(Grade grade){ 
            if ((grade == Grade::A) ? "A" :
           (grade == Grade::B) ? "B" : 
           (grade == Grade::C) ? "C" : 
           (grade == Grade::D) ? "D" : 
           (grade == Grade::F) ? "F" : 
           (grade == Grade::X) ? "In progress" : 
           "Incomplete");
    throw std::runtime_error{std::string{"Invalid Grade: "}};
}

std::ostream& operator<<(std::ostream& ost,const Transcript& transcript){
               ost << "In " << transcript._section << transcript._student << "earned a " << transcript._grade;
               return ost;
               }

void Transcript::save(std::ostream& ost){
    ost << "In " << _section << _student << "earned a " << _grade;
    }
