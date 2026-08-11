#pragma once

#include "cui_window.h"

namespace cui
{
    class WindowSetting final: public Window
    {
    public:
        WindowSetting( CUIScreen& screen );

        void init ( void ) override;

		virtual std::optional<CommandMessage> update( int key ) override { return std::nullopt; }
        // char* handle_input( uint* ) override;
    };
}
