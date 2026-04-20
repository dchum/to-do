#pragma once

#include <memory>
#include <vector>
#include <map>
#include <queue>
#include <optional>
#include <cassert>

#include "cui_container.h"

#include "commandmessage.h"

namespace cui
{


class Window: public Container
{
    std::map<int, CommandId> key_bindings;

protected:
    std::queue<MessagePayload> queue_message_ui_;

    void RegisterCommand( int key, CommandId cmd_id ) noexcept {
        assert( key_bindings.count(key) == 0 );
        key_bindings[key] = cmd_id;
    }

    CommandId GetCommandId( int key ) const {
        assert( key_bindings.size()>0 );
        return key_bindings.at( key );
    }

public:

    Window ( CUIScreen& screen ) :Container(screen) { }

    virtual ~Window()=default;
    
    virtual void init( void ) = 0;

    virtual std::optional<CommandMessage> update( int key ) = 0;
};//cui_window

}