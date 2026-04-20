#pragma once

#include <queue>

#include "common/ui_to_core/commandmessage.h"
#include "common/commands_id.h"

namespace cui
{

// class Command
// {
// public:
//     virtual ~Command() = default;

//     virtual void Execute( std::queue<MessagePayload>& ) = 0;
// };

template<CommandId cmd>
class CommandImpl
{
    static_assert(false, 
        "=================================================================\n"
        "   No specialization of CommandImpl<> for this type!\n\n"
        "=================================================================");
};

template <CommandId cmd>
class Command
{
    CommandImpl<cmd>::type impl_;
public:
    void Execute( CUIScreen& screen, std::queue<MessagePayload>& queue_mes ) {
        impl_.execute( screen, queue_mes );
    }
};

}//namespace cui