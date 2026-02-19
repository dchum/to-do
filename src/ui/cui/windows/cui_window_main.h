#pragma once

#include "cui_window.h"

namespace cui
{
    class WindowMain final: public Window
    {
        Widget* target;
    public:
        WindowMain( CUIScreen& screen );

        void init() override;

        char* handle( uint* ) override;
    };
}