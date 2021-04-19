
#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <gtkmm.h>
#include <cassert>
#include <iostream>
#include <cstring>

template <class T>

class ComboBoxContainer : public Gtk::ComboBoxText {
        T _container;
        Gtk::ComboBoxText cbt_vector;   
        ComboBoxContainer(T container);
        ~ComboBoxContainer();
        };    
#endif
