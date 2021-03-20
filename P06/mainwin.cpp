#include "mainwin.h"


Mainwin::Mainwin(){

    set_default_size(400, 200);
    set_title("SMART");


    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);


    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //FILE//
    //APPENDING TO MENUBAR//
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //APPENDING NEWSCHOOL TO FILE//
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_NewSchool", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //APPENDING QUIT TO FILE//
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);


    //INSERT//
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);
    
    //APPENDING NEWSTUDENT TO INSERT//
    Gtk::MenuItem *menuitem_newstudent = Gtk::manage(new Gtk::MenuItem("_NewStudent", true));
    menuitem_newstudent ->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_newstudent);
    
    //APPENDING NEWPARENT TO INSERT//
    Gtk::MenuItem *menuitem_newparent = Gtk::manage(new Gtk::MenuItem("_NewParent", true));
    menuitem_newparent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_newparent);

    
    //RELATE//
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);
    
    //APPENDING STUDENT TO PARENT IN RELATE//
    Gtk::MenuItem *menuitem_stdtoprt = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_stdtoprt->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_stdtoprt);


    // Make the box and everything in it visible
    vbox->show_all();

}


Mainwin::~Mainwin() { }


// C A L L B A C K S //

void Mainwin::on_new_school_click(){
        //School = new School();
        
     }
     

void Mainwin::on_new_student_click(){
        Gtk::MessageDialog{*this,"ouch!"}.run();
        }
       
 
void Mainwin::on_new_parent_click(){
        }
        
        
void Mainwin::on_student_parent_click(){
        
        
        }
        
        
void Mainwin::on_quit_click(){
        close();
        }                     

void Mainwin::show_data(){
        
        }












































