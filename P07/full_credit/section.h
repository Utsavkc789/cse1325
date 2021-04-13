#ifndef __SECTION_H
#define __SECTION_H

#include "semester.h"
#include "course.h"

class Section{
    private:
        Course _course;
        Semester _semester;
        int _year;
        
    public:
        Section(Course course, Semester semester,int year);
        Section(std::istream& ist);
        void save(std::ostream& ost);
        friend std::ostream& operator<<(std::ostream& ost,Section& section);
        };
        
#endif
