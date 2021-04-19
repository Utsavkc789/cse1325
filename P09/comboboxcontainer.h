
#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <gtkmm.h>
#include <cassert>

template<class T>

class ComboBoxContainer: public Gtk::ComboBoxText{
    public:
        ComboBoxContainer(T container);
        
    private:
        T* _container;
        };    
#endif
