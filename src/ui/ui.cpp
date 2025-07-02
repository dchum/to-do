#include "ui.h"

#include "cui_main.h"


namespace ui
{

Ui_Imp* ui::UI::generate_ui( UI_type type )
{
    Ui_Imp* imp = nullptr;

    switch (type)
    {
        case UI_type::CUI : imp = new cui::CUI_Imp; break;
        /*case UI_type::GUI : factory = new cui::GUI_Imp; break;*/
        
        default:
            break;
    }

    return imp;
}

ui::UI::UI()
    : type_ui_( UI_type::CUI ),
      imp_( generate_ui ( UI_type::CUI ) )
{

}

ui::UI::~UI()
{
    delete imp_;
}

}