#pragma once

#include "cui_window.h"

namespace cui
{
    class WindowStart final: public Window
    {
    public:
        WindowStart( Widget * parent = nullptr );
    };
}