#include "ui_main.h"

#include "cui_main.h"
// #include "gui_main.h" //STUB - пока не реализовано

#include "global_lib.h"

#include "ui_factory.h"
#include "ui_imp.h"

namespace ui
{

class UI
{
private:
    Ui_Imp* imp_;
    UI_type type_ui_;
public:
    UI();
    ~UI();

    void change_ui(UI_type type) {  type_ui_ = type;  }
    void run ( void );
    void sync( void );
    void update( void );
};


ui::UI::UI()
    :imp_( generate_ui(UI_type::CUI) ),
    type_ui_(UI_type::CUI)
{

}

ui::UI::~UI()
{
    delete imp_;
}

}



int ui_main( void )
{
    using ui::UI;

    UI ui;

    return 0;
}
