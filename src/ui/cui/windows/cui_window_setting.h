#pragma once

#include "cui_window.h"

namespace cui
{
    class WindowSetting final: public Window
    {
    public:
        WindowSetting( Widget * parent = nullptr );

        void init ( void ) override;
    };
}