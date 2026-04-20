#pragma once

#include <vector>
#include <optional>

#include "cui_screen.h"
#include "cui_window.h"

#include "commandmessage.h"

namespace cui
{

class CUICore
{
    cui::CUIScreen screen_;
    std::vector<Window*> windows_;

public:
    CUICore ( void );

    std::optional<CommandMessage> handleInput( void );
};

}