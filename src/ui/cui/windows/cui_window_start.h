#pragma once

#include "cui_widget_box.h"

namespace cui
{
    class WindowStart final: public WidgetBox
    {
    public:
        WindowStart( Widget * parent = nullptr );
    };
}