#pragma once

#include "ui_application.h"

#include "cui_screen.h"

namespace cui
{

class CUIApplication : public Application
{
    cui::CUIScreen screen_;
    bool _is_run_;

    void add_new_columns( void );

public:
    CUIApplication ( void );

    void exec ( void ) override;
};

}