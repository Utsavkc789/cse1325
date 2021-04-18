

#ifndef __TRANSCRIPT_H
#define __TRANSCRIPT_H

#include "grade.h"
#include "section.h"
#include "student.h"

class Transcript{
    private:
        Section& _section;
        Student& _student;
        Grade _grade;
        
    public:
        Transcript(Student& student, Section& section);
        void assign_grade(Grade grade);
        friend std::ostream& operator<<(std::ostream& ost,const Transcript& transcript);
        
        };
        
#endif
