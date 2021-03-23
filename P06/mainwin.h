#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <vector>
#include "person.h"
#include "student.h"
#include "parent.h"
#include "school.h"
#include "EntryDialog.h"

class Person;

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
        
    protected:
        void on_new_school_click();
        void on_new_student_click();
        void on_new_parent_click();
        void on_student_parent_click();
        void on_quit_click();
        std::string full_information();
        
    private:
        Gtk::Label *_display;
        std::vector<Student> _students;
        std::vector<Parent> _parents;
        std::vector<Person*> _person;
        School *_school;
        void show_data();
        
   
};
#endif 

