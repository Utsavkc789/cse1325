
#include "transcript.h"

Transcript::Transcript(Student& student, Section& section):_student{student},_section{section}{}
void Transcript::assign_grade(Grade grade){ 
            grade.

}
std::ostream& Transcript::operator<<(std::ostream& ost,const Transcript& transcript){
               ost << "In " << transcript._section << transcript._student << "earned a " << transcript._grade;
               return ost;
               }


