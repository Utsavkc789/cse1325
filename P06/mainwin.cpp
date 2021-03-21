#include "mainwin.h"
#include <string>
#include <iostream>
#include "EntryDialog.h"


Mainwin::Mainwin(){

    set_default_size(400, 200);
    set_title("SMART");


    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    //MENU//
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //FILE//
    //APPENDING TO MENUBAR//
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //APPENDING NEWSCHOOL TO FILE//
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
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
    Gtk::MenuItem *menuitem_newstudent = Gtk::manage(new Gtk::MenuItem("_New Student", true));
    menuitem_newstudent ->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_newstudent);
    
    //APPENDING NEWPARENT TO INSERT//
    Gtk::MenuItem *menuitem_newparent = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
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

     
     _display = Gtk::manage(new Gtk::Label());
     _display->set_hexpand(true);
     _display->set_vexpand(true);
     vbox->add(*_display);
       
      show_data(); 
    // Make the box and everything in it visible
    vbox->show_all();
    
    on_new_school_click();

}


Mainwin::~Mainwin() { }


// C A L L B A C K S //

void Mainwin::on_new_school_click(){
     //delete _school;
     //_school = new School();
           
     }
     

void Mainwin::on_new_student_click(){
        
        Glib::ustring _name,_email, _grade;
        EntryDialog entrydialog1{*this, "Student name?" , true};
        entrydialog1.set_text("Enter text");
        _name=entrydialog1.get_text();
        
        EntryDialog entrydialog2{*this, "Student email?" , true};
        entrydialog1.set_text("Enter text");
        _email=entrydialog1.get_text();
        
        EntryDialog entrydialog3{*this, "Student grade?" , true};
        entrydialog1.set_text("Enter text");
        //_grade=std::atoi(entrydialog1.get_text());
        
        entrydialog1.run();
        entrydialog2.run();
        entrydialog3.run();
        
        //Student s{_name,_email,_grade};
        //_students.push_back(s);
         
        }
       
 
void Mainwin::on_new_parent_click(){
        std::string _name,_email;
        EntryDialog entrydialog1{*this, "Parent name?" , true};
        entrydialog1.set_text("Enter text");
        _name=entrydialog1.get_text();
        
        EntryDialog entrydialog2{*this, "Parent email?" , true};
        entrydialog1.set_text("Enter text");
        _email=entrydialog1.get_text();
        
        entrydialog1.run();
        entrydialog2.run();
        
        Parent p{_name,_email};
        _parents.push_back(p);
        
        }
        
        
void Mainwin::on_student_parent_click(){
        
        }
        
        
void Mainwin::on_quit_click(){
        close();
        }                     

void Mainwin::show_data(){
        std::string s =(   "Students    Parents");
        _display->set_markup(s);
        }
        












































