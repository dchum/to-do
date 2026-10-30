#pragma once

#include <vector>
#include <memory>

#include "common/commands.h"

#include "cui_screen.h"
#include "cui_window.h"


namespace cui
{

class CUICore
{
    cui::CUIScreen screen_;
    std::vector<std::unique_ptr<Window>> windows_;//FIXME - объединить в некий класс, управляющий активными окнами
    size_t index_curr_wnd;//FIXME - объединить в некий класс, управляющий активными окнами

    RegisterCommands reqister_cmds_;//FIXME - объект читающий конфиг и формирующий таблицу команд

public:
    void ProcessEvent( common::EventId );

    common::CommandId GetUserInput( void );
    
    void Update( common::CommandId );
};

}