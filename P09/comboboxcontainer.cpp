
#include "comboboxcontainer.h"
#include <iostream>
#include <sstream>

ComboBoxContainer::ComboBoxContainer(T container):_container{new container}{
        Gtk::ComboBoxText cbt_vector;
        std::ostringstream ost;
        for(auto c : container) {
            ost.str("");
            ost << *c;
            cbt_vector.append(ost.str());
        }
        }
              
