#pragma once

#include "ui_imp.h"

#include "global_lib.h"

namespace ui
{

class Factory_UI_Imp
{
protected:
    Factory_UI_Imp() = default;
public:
    ~Factory_UI_Imp() = default;
    virtual Ui_Imp* get_imp() = 0;
};  


Ui_Imp* generate_ui( UI_type type );//TODO - добавить условие выбора интерфейса

}