#pragma once

#include <queue>

#include "cui/cui_main.h"

namespace ui
{

class Ui final {
    cui::CUICore cui_core_;
    std::queue<AnyCommandMessage>& queue_ui2core_;
    
public:
    Ui (std::queue<AnyCommandMessage>& queue_ui2core)
    :queue_ui2core_(queue_ui2core) { }

    void HandleInput( );
};//class Ui

}//namespace ui
