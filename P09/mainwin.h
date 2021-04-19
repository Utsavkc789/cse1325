#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <climits>
#include <gtkmm.h>
#include "student.h"
#include "parent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "section.h"
#include "transcript.h"
#include "teacher.h"
#include "grade.h"
#include "comboboxcontainer.h"

const std::string EXTENSION = "smart";
const std::string FILE_PATTERN = "*." + EXTENSION;
const std::string COOKIE = "«SmAr✞»"; 
const std::string FILE_VERSION = "0.2";
const std::string VERSION = "0.4.0";


enum class View{SAME, STUDENTS, PARENTS, COURSES, SECTIONS, TEACHERS, TRANSCRIPT};


class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    
     private:
        void show_data(View view = View::SAME); // Display data
        int select_student();
        int select_parent();
        int select(std::string prompt, int max = INT_MAX, int min = 0);
        void error(std::string msg, std::exception& e); 
        std::vector<Student*> students;
        std::vector<Parent*> parents;            
        std::vector<Course*> courses;
        std::vector<Section*> sections;
        std::vector<Transcript*> transcripts;
        std::vector<Teacher*> teachers;
        
        Gtk::Label *display;             
        Gtk::Label *msg;  
        
        std::string filename;
        
        Gtk::ToolButton *button1;
        Gtk::ToolButton *button2;
        Gtk::ToolButton *button3;
        Gtk::ToolButton *button4;
        Gtk::ToolButton *button5;
        Gtk::ToolButton *button6;
        Gtk::ToolButton *button7;
        Gtk::ToolButton *button8;
        Gtk::ToolButton *button9;
        Gtk::ToolButton *button10;
        Gtk::ToolButton *button11;
    
    protected:
        void on_new_school_click();      // Create a new school
        void on_new_student_click();     // Create a new student
        void on_new_parent_click();      // Create a new parent
        void on_easter_egg();            // Load test data
        void on_student_parent_click();  // Relate student and parent
        void on_quit_click();            // Exit the game
        void on_save_click();
        void on_save_as_click();
        void on_open_click();
        void on_about_click();
        void on_new_course_click();
        void on_new_section_click();
        void on_new_transcript_click();
        void on_set_grade_click();
        
                  
   
        };
#endif 

