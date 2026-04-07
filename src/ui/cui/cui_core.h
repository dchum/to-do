#pragma once

#include <vector>


#include "cui_screen.h"
#include "cui_window.h"

namespace cui
{

class CUICore
{
    cui::CUIScreen screen_;
    bool _is_run_;

    std::vector<Window*> windows_;

public:
    CUICore ( void );

    CommandMessage handleInput( void );
};

}