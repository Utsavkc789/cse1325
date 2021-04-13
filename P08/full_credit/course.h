#ifndef __COURSE_H
#define __COURSE_H


#include "subject.h"

class Course{
    private:
        Subject _subject;
        int _grade;
        
        
    public:
        Course(Subject subject, int grade);
        Course(std::istream& ist);
        void save(std::ostream& ost);
        friend std::ostream& operator<<(std::ostream& ost, Course& course);
        };
       
       
#endif
