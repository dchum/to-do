#pragma once

#include "cui_window.h"

namespace cui
{
    class WindowSetting final: public Window
    {
    public:
        WindowSetting( CUIScreen& screen );

        void init ( void ) override;

        // char* handle( uint* ) override;
    };
}