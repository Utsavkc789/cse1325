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
    
    
        // A S S I G N I N G A G R A D E//
    //Append to the Insert menu //
    Gtk::MenuItem *menuitem_grade = Gtk::manage(new Gtk::MenuItem("Assign a grade", true));
    menuitem_grade->signal_activate().connect([this] {this->on_set_grade_click();});
    relatemenu->append(*menuitem_grade);
    
    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);
    
    //         S T U D E N T S
    // Append Students to the View menu
    Gtk::MenuItem *menuitem_view_student = Gtk::manage(new Gtk::MenuItem("_Students", true));
    menuitem_view_student->signal_activate().connect([this] {this->show_data(View::STUDENTS);});
    viewmenu->append(*menuitem_view_student);

    //         P A R E N T S
    // Append Parents to the View menu
    Gtk::MenuItem *menuitem_view_parent = Gtk::manage(new Gtk::MenuItem("_Parents", true));
    menuitem_view_parent->signal_activate().connect([this] {this->show_data(View::PARENTS);});
    viewmenu->append(*menuitem_view_parent);
    
    //         C O U R S E S
    // Append Coursess to Courses to the View menu
    Gtk::MenuItem *menuitem_view_courses = Gtk::manage(new Gtk::MenuItem("_Courses", true));
    menuitem_view_courses->signal_activate().connect([this] {this->show_data(View::COURSES);});
    viewmenu->append(*menuitem_view_courses);
    
    //         S E C T I O N S
    // Append Sections to the View menu
    Gtk::MenuItem *menuitem_view_sections = Gtk::manage(new Gtk::MenuItem("_Sections", true));
    menuitem_view_sections->signal_activate().connect([this] {this->show_data(View::SECTIONS);});
    viewmenu->append(*menuitem_view_sections);
    
    //   T E A C H E R S //
    // Append teachers to the view menu //
    Gtk::MenuItem *menuitem_view_teachers = Gtk::manage(new Gtk::MenuItem("_Teachers", true));
    menuitem_view_teachers->signal_activate().connect([this] {this->show_data(View::TEACHERS);});
    viewmenu->append(*menuitem_view_teachers);
    
    //   T R A N S C R I P T S //
    // Append transcripts to the view menu //
    Gtk::MenuItem *menuitem_view_transcript = Gtk::manage(new Gtk::MenuItem("_Transcripts", true));
    menuitem_view_transcript->signal_activate().connect([this] {this->show_data(View::TRANSCRIPT);});
    viewmenu->append(*menuitem_view_transcript);
    

    
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
 Gtk::Image* button1_image = Gtk::manage(new Gtk::Image{"new.png"});
    button1 = Gtk::manage(new Gtk::ToolButton(*button1_image));
    button1->set_tooltip_markup("Add a new school");
    button1->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(* button1);


//OPENING A FILE//
 Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"open.png"});
    button2 = Gtk::manage(new Gtk::ToolButton(*button2_image));
    button2->set_tooltip_markup("Open a school info");
    button2->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(* button2);

//SAVING A SCHOOL//
 Gtk::Image* button3_image = Gtk::manage(new Gtk::Image{"save.png"});
    button3 = Gtk::manage(new Gtk::ToolButton(*button3_image));
    button3->set_tooltip_markup("Save");
    button3->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(* button3);
    
//SAVING AS//
 Gtk::Image* button4_image = Gtk::manage(new Gtk::Image{"save_as.png"});
    button4 = Gtk::manage(new Gtk::ToolButton(*button4_image));
    button4->set_tooltip_markup("Save as");
    button4->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(* button4);

//ADDING NEW STUDENT//
 Gtk::Image* button5_image = Gtk::manage(new Gtk::Image{"student.png"});
    button5 = Gtk::manage(new Gtk::ToolButton(*button5_image));
    button5->set_tooltip_markup("Add a new student");
    button5->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(* button5);
    
//ADDING NEW PARENT//
 Gtk::Image* button6_image = Gtk::manage(new Gtk::Image{"parent.png"});
    button6 = Gtk::manage(new Gtk::ToolButton(*button6_image));
    button6->set_tooltip_markup("Add a new parent");
    button6->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(* button6);

//RELATING PARENT TO STUDENT//
 Gtk::Image* button7_image = Gtk::manage(new Gtk::Image{"ps_relate.png"});
    button7 = Gtk::manage(new Gtk::ToolButton(*button7_image));
    button7->set_tooltip_markup("Relate parent to a student");
    button7->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(* button7);

// ADDIND COURSES //
  Gtk::Image* button8_image = Gtk::manage(new Gtk::Image{"course.png"});
    button8 = Gtk::manage(new Gtk::ToolButton(*button8_image));
    button8->set_tooltip_markup("all courses available");
    button8->signal_clicked().connect([this] {this->on_new_course_click();});
    toolbar->append(* button8);

// ADDING SECTIONS //
  Gtk::Image* button9_image = Gtk::manage(new Gtk::Image{"section.png"});
    button9 = Gtk::manage(new Gtk::ToolButton(*button9_image));
    button9->set_tooltip_markup("all sections available");
    button9->signal_clicked().connect([this] {this->on_new_section_click();});
    toolbar->append(* button9);      
    
//ADDING GRADES //
Gtk::Image* button10_image = Gtk::manage(new Gtk::Image{"Grades.png"});
    button10 = Gtk::manage(new Gtk::ToolButton(*button10_image));
    button10->set_tooltip_markup("All grades of students");
    button10->signal_clicked().connect([this] {this->on_set_grade_click();});
    toolbar->append(* button10);


//   ADDING TEACHERS //
Gtk::Image* button11_image = Gtk::manage(new Gtk::Image{"teachers.png"});
    button11 = Gtk::manage(new Gtk::ToolButton(*button11_image));
    button11->set_tooltip_markup("All teachers Available");
    button11->signal_clicked().connect([this] {this->show_data(View::TEACHERS);});
    toolbar->append(* button11);
    
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
    courses.clear();
    sections.clear();
    show_data();
}

void Mainwin::on_new_student_click() {  
    try {
        EntryDialog name{*this, "Student name?"};
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return; 
        EntryDialog email{*this, "Student email?"};
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;

        int grade = select("Student grade?", 12, 1);
        if(grade < 1) return;
        
        students.push_back(new Student{name.get_text(), email.get_text(), grade});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data(View::STUDENTS);
}

void Mainwin::on_new_parent_click() {     
    try {
        EntryDialog name{*this, "Parent name?"}; 
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;
        
        EntryDialog email{*this, "Parent email?"}; 
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;
        
        parents.push_back(new Parent{name.get_text(), email.get_text()});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data(View::PARENTS);
}


void Mainwin::on_student_parent_click() {  // Relate student and parent
   try{ Gtk::Dialog d{"Relate students and Parents", *this};
        auto vbox = d.get_content_area();
        
        ComboBoxContainer<std::vector<Student*>> cbt_students(students);
        vbox->pack_start(cbt_students);
        
        ComboBoxContainer<std::vector<Parent*>> cbt_parents(parents);
        vbox->pack_start(cbt_parents);

        d.add_button("Relate", 1);
        d.add_button("Cancel", 0);
        d.show_all();
        if(d.run() != 1) return;       
        
        Student& student = *students.at(cbt_students.get_active_row_number());
        Parent& parent = *parents.at(cbt_parents.get_active_row_number());
        
        student.add_parent(parent);
        parent.add_student(student);
        }
        
     catch(std::exception& e) {
        error("Invalid input",e);
    }
    show_data(View::STUDENTS);
}



void Mainwin::on_save_click() {
    try {
        std::ofstream ofs{filename};
        
      
        ofs << COOKIE << '\n';  
        ofs << FILE_VERSION << '\n';     
        
        ofs << students.size() << '\n';
        for(Student* student : students) student->save(ofs);
        ofs << parents.size() << '\n';
        for(Parent* parent : parents) parent->save(ofs);
  
        for(Student* student : students) student->save_aggregates(ofs);
        for(Parent* parent : parents) parent->save_aggregates(ofs);

        ofs << courses.size() << '\n';
        for(Course* course : courses) course->save(ofs);
        
        ofs << sections.size() << '\n';
        for(Section* section : sections) section->save(ofs);
        
        ofs << teachers.size() << '\n';
        for(Teacher* teacher : teachers) teacher->save(ofs);
        
        ofs << transcripts.size() << '\n';
        for(Transcript* transcript : transcripts) transcript->save(ofs);
        
        if(!ofs) throw std::runtime_error{"Error writing file"};
    } catch(std::exception& e) {
        error("Unable to save school", e);
    }
}
  
void Mainwin::on_save_as_click(){ 
    Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern(FILE_PATTERN);
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Save", Gtk::RESPONSE_OK);

    int result = dialog.run();
    if(result == Gtk::RESPONSE_OK) {
        filename = dialog.get_filename();
        on_save_click();
}
}
        
   
void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("smart files");
    filter_smart->add_pattern(FILE_PATTERN);
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    int result = dialog.run();

    if (result == Gtk::RESPONSE_OK) {
        try {
            std::ifstream ifs{dialog.get_filename()};
            
            on_new_school_click();
            show_data();
            filename = dialog.get_filename();
            
            std::string cookie;
            std::getline(ifs, cookie);
            if(cookie != COOKIE) throw std::runtime_error{"Not a smart file"};
            std::string version;
            std::getline(ifs, version);
            if(version > FILE_VERSION) throw std::runtime_error{"Unsupported file version"};
            
            int size;
            ifs >> size; ifs.ignore(32767, '\n');
            while(size--) students.push_back(new Student{ifs});
            
            ifs >> size; ifs.ignore(32767, '\n');
            while(size--) parents.push_back(new Parent{ifs});
            
            std::ostringstream oss;
            std::map<std::string, Parent*> parent_aggregates;
            for(Parent* p : parents) {
                oss.str("");
                oss << *p;
                parent_aggregates[oss.str()] = p;
            }
            for(Student* s : students) s->load_aggregates(ifs, parent_aggregates);
            
            std::map<std::string, Student*> student_aggregates;
            for(Student* s : students) {
                oss.str("");
                oss << *s;
                student_aggregates[oss.str()] = s;
            }
            for(Parent* p : parents) p->load_aggregates(ifs, student_aggregates);
            
            if(version >= "0.2") {
                ifs >> size; ifs.ignore(32767, '\n');
                while(size--) courses.push_back(new Course{ifs});

                ifs >> size; ifs.ignore(32767, '\n');
                while(size--) sections.push_back(new Section{ifs}); 
                
                ifs >> size; ifs.ignore(32767, '\n');
                while(size--) teachers.push_back(new Teacher{ifs}); 
                
                ifs >> size; ifs.ignore(32767, '\n');
                while(size--) transcripts.push_back(new Transcript{ifs}); 
                           
            }

            
            
            if(!ifs) throw std::runtime_error{"File contents bad"};
            show_data();
        } catch (std::exception& e) {
            error("Unable to open school", e);
        }
    }
}

              
        


void Mainwin::on_quit_click() {
    close();
}



// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::show_data(View view) {
    static View current_view;
    if(view != View::SAME) current_view = view;
    
    std::ostringstream oss;
    
    if(current_view == View::STUDENTS) {
        oss << "    <b><big>Students</big></b>\n\n";
        for(int i=0; i<students.size(); ++i) 
            oss << students.at(i)->full_info() << '\n';
            
    } else if(current_view == View::PARENTS) {
        oss << "    <b><big>Parents</big></b>\n\n";
        for(int i=0; i<parents.size(); ++i) 
            oss << parents.at(i)->full_info() << '\n';

    } else if(current_view == View::COURSES) {
        oss << "    <b><big>Courses</big></b>\n\n";
        for(auto course : courses) 
            oss << *course << '\n';

    } else if(current_view == View::SECTIONS) {
        oss << "    <b><big>Sections</big></b>\n\n";
        for(auto section : sections) 
            oss << *section << '\n';
    
    }  else if(current_view == View::TEACHERS) {
        oss << "    <b><big>TEACHERS</big></b>\n\n";
        for(int i=0; i<teachers.size(); ++i) 
            oss << teachers.at(i)->full_info() << '\n';
            
    }  else if(current_view == View::TRANSCRIPT) {
        oss << "    <b><big>TRANSCRIPTS</big></b>\n\n";
        for(int i=0; i<transcripts.size(); ++i) 
            oss << *transcripts.at(i) << '\n';
            
    }  else {
        current_view = View::STUDENTS;
    }
            
    display->set_markup(oss.str());
}

int Mainwin::select_student() {
    std::string prompt = "Select Student\n\n";
    for(int i=0; i<students.size(); ++i)
        prompt += std::to_string(i) + ") " + students[i]->to_string() +'\n';
    return select(prompt, students.size()-1);
}

int Mainwin::select_parent() {
    std::string prompt = "Select Parent\n\n";
    for(int i=0; i<parents.size(); ++i)
        prompt += std::to_string(i) + ") " + parents[i]->to_string() +'\n';
    return select(prompt, parents.size()-1);
}

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
                selection = -1; 
                break;
            }
        } catch(std::exception& e) {
            error("Invalid selection", e);
        }
    }
    return selection;
}


void Mainwin::on_set_grade_click(){
       try {
        Gtk::Dialog d{"Assign Grade",*this};
        auto vbox = d.get_content_area();
        
        ComboBoxContainer<std::vector<Transcript*>>cbt_transcripts(transcripts);
        vbox->pack_start(cbt_transcripts);
        
        d.add_button("Cancel", 0);
        d.add_button("A", 1);
        d.add_button("B", 2);
        d.add_button("C", 3);
        d.add_button("D", 4);
        d.add_button("F", 5);
        d.add_button("I", 6);
        d.add_button("X", 7);
        d.show_all();
        int r = d.run();
        if(r == 0) return;       
        Grade grade = ((r==1) ? Grade::A :
                            (r==2) ? Grade::B :
                            (r==3) ? Grade::C:
                            (r==4) ? Grade::D :
                            (r==5) ? Grade::F :
                            (r==6) ? Grade::I :
                            Grade::X);
                            
        
        
    } catch(std::exception& e) {
        error("Invalid input",e);
    }
    show_data(View::TRANSCRIPT);
    
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
      try{
           std::string s = {"Subject name?\n\n"};
            for(int i=0; i<subjects_vector.size(); ++i){
                s +=std::to_string(i) + ") " + subject_to_string.at(subjects_vector[i]) + '\n';
                
                }
            
            EntryDialog ds{*this, s};
            if(ds.run() == Gtk::RESPONSE_OK) ds.hide();
            
            else return;
            
            Subject subject = subjects_vector.at(std::stoi(ds.get_text()));
            
            EntryDialog grade {*this, "Grade (1-12)?"};
            
            if(grade.run() == Gtk::RESPONSE_OK) grade.hide();
            else return;
            
            courses.push_back(new Course {subject, std::stoi(grade.get_text())});
            }
            
            catch(std::exception& e){
                error("Invalid input",e);
                }
                show_data(View::COURSES);
                
                
}
  
    
 void Mainwin::on_new_section_click(){
             try {
        Gtk::Dialog d{"Course", *this};
        auto vbox = d.get_content_area();
        
        ComboBoxContainer<std::vector<Course*>> cbt_courses(courses);
        vbox->pack_start(cbt_courses);
        
        d.add_button("Cancel", 0);
        d.add_button("Select", 1);
        d.show_all();
        if(d.run() != 1) return;       
        Course& course = *courses.at(cbt_courses.get_active_row_number());
        
        Gtk::Dialog d1{"Teacher",*this};
        vbox = d1.get_content_area();
        ComboBoxContainer<std::vector<Teacher*>>cbt_teachers(teachers);
        vbox->pack_start(cbt_teachers);
        
        d1.add_button("Cancel", 0);
        d1.add_button("Select", 1);
        d1.show_all();
        if(d1.run() != 1) return;       
        Teacher& teacher = *teachers.at(cbt_teachers.get_active_row_number());
        
        // Select Semester and year
        EntryDialog m{*this, "Select Semester and Year", false, 
            Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_CANCEL};
        m.add_button("Fall", 1);
        m.add_button("Spring", 2);
        m.add_button("Summer", 3);
        m.set_text("2021");
        m.show_all();
        int r = m.run();
        if(!r) return;
        Semester semester = (r==1) ? Semester::FALL :
                           ((r==2) ? Semester::SPRING : Semester::SUMMER);
        
        int year = std::stoi(m.get_text());

        sections.push_back(new Section{course, semester, year,teacher});
    } catch(std::exception& e) {
        error("Invalid input",e);
    }
    show_data(View::SECTIONS);
    
    }   
        
    

void Mainwin::on_easter_egg() {
    const std::vector<std::string> names{
        "Enrique Young",  // student
        "Isabella Young", // student
        "Biniti Adani", // student
        "James Montgomery", //student
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
        for(int i=0; i<grades.size(); ++i)
            students.push_back(new Student{names[i], emails[i], grades[i]});
        for(int i=grades.size(); i<names.size(); ++i)
           parents.push_back(new Parent{names[i], emails[i]});
        for(int i=grades.size(); i<names.size(); ++i)
            teachers.push_back(new Teacher{names[i],emails[i]});
        students[0]->add_parent(*parents[0]); parents[0]->add_student(*students[0]);
        students[0]->add_parent(*parents[1]); parents[1]->add_student(*students[0]);
        students[1]->add_parent(*parents[0]); parents[0]->add_student(*students[1]);
        students[1]->add_parent(*parents[1]); parents[1]->add_student(*students[1]);
        students[2]->add_parent(*parents[2]); parents[2]->add_student(*students[2]);
        students[2]->add_parent(*parents[1]); parents[1]->add_student(*students[2]);
        students[3]->add_parent(*parents[1]); parents[1]->add_student(*students[3]);
        students[3]->add_parent(*parents[2]); parents[2]->add_student(*students[3]);
        students[3]->add_parent(*parents[3]); parents[3]->add_student(*students[3]);
        
        
        int i= 0;
        while(i < 31) {
            for(Subject subject : subjects_vector) {
                int grade = std::min(i++ % 3 + 1, 12);
                courses.push_back(new Course{subject, grade});
            }
        }
        
        for(int i=0; i<=2; ++i) {
            Semester semester = static_cast<Semester>(i);
            for(int j=0; j<=15; ++j) {
                Teacher teacher = *teachers.at(rand()% teachers.size());
                Course course = *courses.at(rand() % courses.size());
                Student student  = *students.at(rand() % students.size());
                sections.push_back(new Section{course,semester,2021,teacher});
                Section section = *sections.at(rand()% sections.size());  
                transcripts.push_back(new Transcript{student,section});     
            }
  
          } 
          
          
        show_data();
    } catch(std::exception& e) {
        error("Easter Egg failed", e);
    }
    }





void Mainwin::error(std::string msg, std::exception& e) {
    Gtk::MessageDialog{*this, msg + '\n' + e.what(), false, Gtk::MESSAGE_WARNING}.run();
}
