#pragma once 

#include "global_lib.h"
#include "ui_imp.h"


namespace ui
{

class UI
{
private:
    Ui_Imp* imp_;
    UI_type type_ui_;

    Ui_Imp* generate_ui( UI_type type );
    
public:
    UI ();
    ~UI();

    void change_ui(UI_type type) {  type_ui_ = type;  }
    void run   ( void );
    void sync  ( void );
};

}