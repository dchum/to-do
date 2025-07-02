#pragma once

#include "cui_lib.h"
#include "cui_widget.h"

#include "ui_imp.h"

namespace cui
{

class CUI_Imp final: public ui::Ui_Imp
{
private:
    static Widget* wdts_;

public:
    CUI_Imp();
    ~CUI_Imp() { delete wdts_; }

    void init ( void );
};

}