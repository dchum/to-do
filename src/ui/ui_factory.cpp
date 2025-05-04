#include "ui_factory.h"

#include "cui_main.h"

#include "global_lib.h"

namespace ui
{




Ui_Imp* generate_ui( UI_type type )
{
    Factory_UI_Imp* factory = nullptr;

    switch (type)
    {
    case UI_type::CUI :
        factory = new cui::CUI_Factory_UI_Imp;
        break;
    /*case UI_type::GUI :
        factory = new cui::GUI_Factory_UI_Imp;
        break;*/
    default:
        break;
    }

    return factory->get_imp();
}

}


