#include "mainwin.h"
#include "entrydialog.h"

const int MAX_STUDENTS = 100;
const int MAX_PARENTS = 400;
Mainwin::Mainwin() {

    students.reserve(MAX_STUDENTS);
    parents.reserve(MAX_PARENTS);

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("SMART");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    
    //      SAVE 
    // Appending Save to File menu
     Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    
    //    SAVE_AS
    //Appending save_as to File menubar
    Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save as", true));
    menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveas);

    //         N E W   S C H O O L
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     I N S E R T
    // Create an Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //         N E W   S T U D E N T
    // Append New Student to the Insert menu
    Gtk::MenuItem *menuitem_new_student = Gtk::manage(new Gtk::MenuItem("New _Student", true));
    menuitem_new_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_new_student);

    //         N E W   P A R E N T
    // Append New Parent to the Insert menu
    Gtk::MenuItem *menuitem_new_parent = Gtk::manage(new Gtk::MenuItem("New _Parent", true));
    menuitem_new_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_new_parent);

    //         T E S T   D A T A
    // Append Test Data to the Insert menu
    Gtk::MenuItem *menuitem_test_data = Gtk::manage(new Gtk::MenuItem("_Test Data", true));
    menuitem_test_data->signal_activate().connect([this] {this->on_easter_egg();});
    insertmenu->append(*menuitem_test_data);
    
        //       C  O  U  R  S  E  S          
    Gtk::MenuItem *menuitem_course_data = Gtk::manage(new Gtk::MenuItem("_courses", true));
    menuitem_course_data->signal_activate().connect([this] {this->on_new_course_click();});
    insertmenu->append(*menuitem_course_data);

    //      S  E  C  T  I  O  N  S
      Gtk::MenuItem *menuitem_section_data = Gtk::manage(new Gtk::MenuItem("_sections", true));
    menuitem_section_data->signal_activate().connect([this] {this->on_new_section_click();});
    insertmenu->append(*menuitem_section_data);
    
    //     R E L A T E
    // Create a Relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    //         S T U D E N T  T O  P A R E N T
    // Append Student to Parent to the Insert menu
    Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_student_parent->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_student_parent);
    
    
    //HELP//
    
   Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);
    
    
    //A B O U T//
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);
    
    
    
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);
    
    
//  File  
// ADDING NEW SCHOOL ICON TO TOOLBAR //

 Gtk::Image* button1_image = Gtk::manage(new Gtk::Image{"button1.png"});
    button1 = Gtk::manage(new Gtk::ToolButton(*button1_image));
    button1->set_tooltip_markup("Add a new school");
    button1->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(* button1);

//ADDING NEW SCHOOL//
 Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"button2.png"});
    button2 = Gtk::manage(new Gtk::ToolButton(*button2_image));
    button2->set_tooltip_markup("Open a school info");
    button2->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(* button2);

//SAVING A SCHOOL//
 Gtk::Image* button3_image = Gtk::manage(new Gtk::Image{"button3.png"});
    button3 = Gtk::manage(new Gtk::ToolButton(*button3_image));
    button3->set_tooltip_markup("Save");
    button3->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(* button3);
    
//SAVING AS//
 Gtk::Image* button4_image = Gtk::manage(new Gtk::Image{"button4.png"});
    button4 = Gtk::manage(new Gtk::ToolButton(*button4_image));
    button4->set_tooltip_markup("Save as");
    button4->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(* button4);

//ADDING NEW STUDENT//
 Gtk::Image* button5_image = Gtk::manage(new Gtk::Image{"button5.png"});
    button5 = Gtk::manage(new Gtk::ToolButton(*button5_image));
    button5->set_tooltip_markup("Add a new student");
    button5->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(* button5);
    
//ADDING NEW PARENT//
 Gtk::Image* button6_image = Gtk::manage(new Gtk::Image{"button6.png"});
    button6 = Gtk::manage(new Gtk::ToolButton(*button6_image));
    button6->set_tooltip_markup("Add a new parent");
    button6->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(* button6);

//RELATING PARENT TO STUDENT//
 Gtk::Image* button7_image = Gtk::manage(new Gtk::Image{"button7.png"});
    button7 = Gtk::manage(new Gtk::ToolButton(*button7_image));
    button7->set_tooltip_markup("Relate parent to a student");
    button7->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(* button7);

// ADDIND COURSES //
  Gtk::Image* button8_image = Gtk::manage(new Gtk::Image{"button8.png"});
    button8 = Gtk::manage(new Gtk::ToolButton(*button8_image));
    button8->set_tooltip_markup("all courses available");
    button8->signal_clicked().connect([this] {this->on_new_course_click();});
    toolbar->append(* button8);

// ADDING SECTIONS //
  Gtk::Image* button9_image = Gtk::manage(new Gtk::Image{"button9.png"});
    button9 = Gtk::manage(new Gtk::ToolButton(*button9_image));
    button9->set_tooltip_markup("all sections available");
    button9->signal_clicked().connect([this] {this->on_new_section_click();});
    toolbar->append(* button9);    
    
    // /////////////////////////// ////////////////////////////////////////////
    // D I S P L A Y
    // Provide a text entry box to show the data
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    // vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    on_new_school_click();
}

Mainwin::~Mainwin() { }


// C A L L B A C K S //


void Mainwin::on_new_school_click() {
    students.clear();
    parents.clear();
    show_data();
}

void Mainwin::on_new_student_click() {     // Create a new student
    try {
        EntryDialog name{*this, "Student name?"};
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;
        
        EntryDialog email{*this, "Student email?"};
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;

        int grade = select("Student grade?", 12, 1);
        if(grade < 1) return;
        
        students.push_back(Student{name.get_text(), email.get_text(), grade});
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Invalid entry!"+std::string{e.what()}}.run();
    }
    show_data();
}
void Mainwin::on_new_parent_click() {      // Create a new parent
    try {
        EntryDialog name{*this, "Parent name?"}; 
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;
        
        EntryDialog email{*this, "Parent email?"}; 
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;
        
        parents.push_back(Parent{name.get_text(), email.get_text()});
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, e.what()}.run();
    }
    show_data();
}
void Mainwin::on_student_parent_click() {  // Relate student and parent
    try {
        int student = select_student(); if (student < 0) return;
        int parent = select_parent(); if (parent < 0) return;
        students.at(student).add_parent(parents.at(parent));
        parents.at(parent).add_student(students.at(student));
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, e.what()}.run();
    }
    show_data();
}



void Mainwin::on_save_click() {
    Gtk::FileChooserDialog dialog("Please choose a file ",Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
      
      dialog.set_transient_for(*this);
      
      auto filter_smart=Gtk::FileFilter::create();
      filter_smart->set_name("SMART files");
      filter_smart->add_pattern("*.smart");
      dialog.add_filter(filter_smart);
      
      auto filter_any = Gtk::FileFilter::create();
      filter_any->set_name("Any files");
      filter_any->add_pattern("*");
      dialog.add_filter(filter_any);
      
      dialog.set_filename("untitled.smart");
      
      dialog.add_button("_Cancel",0);
      dialog.add_button("_Save",1);
      
      int result = dialog.run();
      
      if (result==1){
            try{
                filename=dialog.get_filename();
                std::ofstream ofs{filename}; 
                ofs << students.size() << '\n';               
                for(int i=0; i<students.size(); i++){  students.at(i).save(ofs); }
                ofs << parents.size() << '\n';
                for(int i=0; i<parents.size(); i++){  parents.at(i).save(ofs); }
                
                if(!ofs){
                    throw std::runtime_error{"Invalid file contents"};
                    }
                    }
                  
            catch(std::exception e){
                  Gtk::MessageDialog{*this,"Unable to save info"}.run();
                 
                   }
         }
}
  
void Mainwin::on_save_as_click(){ 
        on_save_click();
}
        
   
void Mainwin::on_open_click(){
      Gtk::FileChooserDialog dialog("Please choose a file to open",Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
      
      dialog.set_transient_for(*this);
      
      auto filter_smart=Gtk::FileFilter::create();
      filter_smart->set_name("smart files");
      filter_smart->add_pattern("*.smart");
      dialog.add_filter(filter_smart);
      
      auto filter_any = Gtk::FileFilter::create();
      filter_any->set_name("any File");
      filter_any->add_pattern("*");
      dialog.add_filter(filter_any);
      
      dialog.set_filename("untitled.smart");
      
      dialog.add_button("_Cancel",0);
      dialog.add_button("_Open",1);
      
      int result = dialog.run();
      
      if (result==1){
            try{
                filename = dialog.get_filename();
                std::ifstream ist{filename};
                on_new_school_click(); 

                int _student,_parent;
                ist >> _student;
                
               for(int i=0; i<_student;i++){
                      Student s{ist};
                      students.push_back(s);
                      }
                ist >> _parent;
                 for(int i=0; i<_parent;i++){
                      Parent p{ist};
                      parents.push_back(p);
                      }
                
                show_data();
                if(!ist){
                    throw std::runtime_error{"Invalid file contents"};
                    
                    } 
                    }
                  
            catch(std::exception &e){
                  Gtk::MessageDialog{*this, "Cannot open file"}.run();
                 
                   }
         }
}
              
        


void Mainwin::on_quit_click() {
    close();
}



// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::show_data() {
    std::string s;
    s += "    Students\n\n";
    for(int i=0; i<students.size(); ++i) 
        s += students.at(i).full_info() + '\n';
    s += "\n    Parents\n\n";
    for(int i=0; i<parents.size(); ++i) 
        s += parents.at(i).full_info() + '\n';

    display->set_markup(s);
}

// Returns index of selected student, or -1 for Cancel / Close
int Mainwin::select_student() {
    std::string prompt = "Select Student\n\n";
    for(int i=0; i<students.size(); ++i)
        prompt += std::to_string(i) + ") " + students[i].to_string() +'\n';
    return select(prompt, students.size()-1);
}

// Returns index of selected parent, or -1 for Cancel / Close
int Mainwin::select_parent() {
    std::string prompt = "Select Parent\n\n";
    for(int i=0; i<parents.size(); ++i)
        prompt += std::to_string(i) + ") " + parents[i].to_string() +'\n';
    return select(prompt, parents.size()-1);
}



void Mainwin::on_about_click(){
      Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("SMART");
    auto logo = Gdk::Pixbuf::create_from_file("smart_logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 0.3.0");
    dialog.set_copyright("Copyright 2021");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"UTSAV KC"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Created by UTSAV KC   Special thanks to Professor George Rice.                                                                Artwork by Unknown liscensed under the Flaticon liscense "};
    dialog.set_artists(artists);
    dialog.run();
    }
    
    
void Mainwin::on_new_course_click(){
           /*{
        EntryDialog name{*this, "Subject name?"};
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;

        int grade = select("Student grade?", 12, 1);
        if(grade < 1) return;
        Subject s;
        _courses.push_back(s, grade});
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Invalid entry!"+std::string{e.what()}}.run();
    }
    show_data();*/
}
  
    
 void Mainwin::on_new_section_click(){
    }   
        
    

// Returns int between [min, max], or min-1 for Cancel / Close
int Mainwin::select(std::string prompt, int max, int min) {
    int selection = min-1;
    while(true) {
        try {
            EntryDialog dialog{*this, prompt}; 
            int response = dialog.run();
            if(response == Gtk::RESPONSE_OK) {
                selection = std::stoi(dialog.get_text());
                if (min <= selection && selection <= max) break;
                throw std::out_of_range{"Invalid selection"};
            } else {
                selection = min-1; 
                break;
            }
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, e.what()}.run();
        }
    }
    return selection;
}

void Mainwin::on_easter_egg() {
    const std::vector<std::string> names{
        "Enrique Young",  
        "Isabella Young", 
        "Biniti Adani", 
        "James Montgomery", 
        "Robert Young",
        "Susan Young",
        "Nimish Adani",
        "Oscar Montgomery",
      };
    const std::vector<std::string> emails{
        "eyoung@gmale.com",
        "iyoung@fmale.com",
        "biniti@myschool.org",
        "james.q.montgomery@british.uk",
        "bob-young@woohoo.com",
        "youngsr@uta.edu",
        "nimish.adani@hatmail.com",
        "oscar.the.m@funville.net",
      };
    const std::vector<int> grades {
          1, 5, 3, 12, // For students only
      };
    try {
        on_new_school_click();
        for(int i=0; i<grades.size(); ++i)
            students.push_back(Student{names[i], emails[i], grades[i]});
        for(int i=grades.size(); i<names.size(); ++i)
           parents.push_back(Parent{names[i], emails[i]});
        students[0].add_parent(parents[0]); parents[0].add_student(students[0]);
        students[0].add_parent(parents[1]); parents[1].add_student(students[0]);
        students[1].add_parent(parents[0]); parents[0].add_student(students[1]);
        students[1].add_parent(parents[1]); parents[1].add_student(students[1]);
        students[2].add_parent(parents[2]); parents[2].add_student(students[2]);
        students[2].add_parent(parents[1]); parents[1].add_student(students[2]);
        students[3].add_parent(parents[1]); parents[1].add_student(students[3]);
        students[3].add_parent(parents[2]); parents[2].add_student(students[3]);
        students[3].add_parent(parents[3]); parents[3].add_student(students[3]);
        show_data();
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, e.what()}.run();
    }
}

