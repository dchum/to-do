#pragma once

#include <memory>
#include <vector>
#include <map>
#include <queue>

#include "cui_container.h"
#include "cui_command.h"

#include "common/ui_to_core/commandmessage.h"

namespace cui
{


class Window: public Container
{
protected:
    std::map<CommandId, Command<CommandId> > cmd_action_;
    std::map<int, CommandId> cmd_input_;

    std::queue<MessagePayload> queue_message_ui_;

    virtual cui::Command& get_command_binding(unsigned int key) = 0;

public:

    Window ( CUIScreen& screen ) :Container(screen) { }

    virtual ~Window()=default;
    
    virtual void init( void ) = 0;

    virtual std::optional<CommandMessage> update( int key ) = 0;
};//cui_window

}