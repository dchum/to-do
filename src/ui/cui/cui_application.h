#pragma once

#include <vector>

#include "ui_application.h"

#include "cui_screen.h"
#include "cui_window.h"

namespace cui
{

class CUIApplication : public Application
{
    cui::CUIScreen screen_;
    bool _is_run_;

    std::vector<Window*> windows_;

public:
    CUIApplication ( void );

    void exec ( void ) override;
};

}