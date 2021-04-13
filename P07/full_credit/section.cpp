#include "section.h"

Section(Course course, Semester semester,int year):_course{course},_semester{semester},_year{year}{}

Section(std::istream& ist):{
        ist >> _course;
        ist >> _semester;
        ist >> _year;
        ist.ignore(32767, '\n');
        }
        
        
void save(std::ostream& ost){
        ost << _course << '\n' << _semester << '\n' << _year ;
        }
        
        
std::ostream& operator<<(std::ostream& ost,Section& section){
         ost << Course::to_string(course) << "for" << _semester << "2021" ;    
         return ost;
         }
