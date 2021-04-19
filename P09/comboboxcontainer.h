
#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <gtkmm.h>
#include <cassert>
#include <iostream>
#include <vector>

template <class T>

class ComboBoxContainer : public Gtk::ComboBoxText {
        public:
        ComboBoxContainer(T container){
        std::ostringstream ost;
        for(auto c : container) {
            ost.str("");
            ost << *c;
            append(ost.str());
        }
        }
        };    
#endif
