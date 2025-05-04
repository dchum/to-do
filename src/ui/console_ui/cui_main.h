#pragma once

#include "cui_lib.h"
#include "cui_widget.h"

#include "ui_factory.h"

namespace cui
{

class CUI_Imp;

class CUI_Factory_UI_Imp : public ui::Factory_UI_Imp
{
private:
    static CUI_Imp* imp_;
public:
    CUI_Factory_UI_Imp();
    ~CUI_Factory_UI_Imp();

    ui::Ui_Imp* get_imp( void ) override;
};

}