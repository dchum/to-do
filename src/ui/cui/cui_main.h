#pragma once

#include <vector>
#include <memory>

#include "common/commands.h"

#include "cui_screen.h"
#include "cui_window.h"

#include "commandmessage.h"

namespace cui
{

class CUICore
{
    cui::CUIScreen screen_;
    std::vector<std::unique_ptr<Window>> windows_;
    size_t index_curr_wnd;

    const RegisterCommands * reqister_cmds_;

public:
    // std::optional<CommandMessage> handleInput( void );
    void ProcessEvent( common::EventId );

    common::CommandId GetUserInput( void );
    
    void Update( common::CommandId );
};

}