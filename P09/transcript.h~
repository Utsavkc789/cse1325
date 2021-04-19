

#ifndef __TRANSCRIPT_H
#define __TRANSCRIPT_H

#include "grade.h"
#include "section.h"
#include "student.h"

class Transcript {
    private:
        Section _section;
        Student _student;
        Grade _grade;
        
    public:
        Transcript(Student& student, Section& section);
        Transcript(std::istream& ist);
        void assign_grade(Grade grade);
        friend std::ostream& operator<<(std::ostream& ost,const Transcript& transcript);
        void save(std::ostream& ost);
        };
             
#endif
