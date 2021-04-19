  
#ifndef __SECTION_H
#define __SECTION_H

#include "course.h"
#include "semester.h"
#include "teacher.h"

class Section {
  private:
    Course _course;
    Semester _semester;
    int _year;
    Teacher _teacher;
  
  public:
    Section(Course course, Semester semester, int year, Teacher teacher); // Teacher teacher
    Section(std::istream& ist);
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Section& section);
  
};

#endif
