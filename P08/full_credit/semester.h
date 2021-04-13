#include <iostream>
#include <vector>


enum Semester { FALL, SPRING, SUMMER};
std::ostream& operator<<(std::ostream& ost, Semester semester);
std::string load_subject(std::istream& ist);
