#include <iostream>
#include <vector>


enum Subject { READING, WRITING, MATH, SCIENCE, HISTORY, ART, MUSICSPORTS};
std::ostream& operator<<(std::ostream& ost, Subject subject);
std::string load_subject(std::istream& ist);
