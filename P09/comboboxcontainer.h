

#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <iostream>
#include <gtkmm.h>
#include <cassert>


template <class T>

ComboboxContainer: public Gtk::ComboboxText{
    public:
        ComboboxContainer(T container);
        };
        
#endif
