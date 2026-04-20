#pragma once

#include <queue>

#include "cui/cui_main.h"

namespace ui
{

class Ui final {
    cui::CUICore cui_core_;
    std::queue<CommandMessage>* queue_ui2core_ = nullptr;
    
public:
    void init ( std::queue<CommandMessage>& queue_ui2core );

    void HandleInput( );
};//class Ui

}//namespace ui
