#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <vector>
#include "person.h"
#include "student.h"
#include "parent.h"
#include "school.h"

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
        
    private:
        Gtk::Label *_display;
        std::vector<Student> _students;
        std::vector<Parent> _parents;
        void show_data();
   
};
#endif 

