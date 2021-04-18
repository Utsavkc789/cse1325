
#ifndef __GRADE_H
#define __GRADE_H

#include <string>

enum class Grade{A, B, C, D, E, F, I, X};

std::ostream& operator<<(std::ostream& ost, const Grade& grade); 
Grade load_grade(std::istream& ist); 

#endif

