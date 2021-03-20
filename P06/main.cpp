#include "student.h"
#include "parent.h"
#include "mainwin.h"
#include <gtkmm.h>

int main (int args, char* argv[]) {
    auto app = Gtk::Application::create(args, argv, "edu.uta.cse1325.nim.v1_0");
    Mainwin win;
    return app->run(win);
}

