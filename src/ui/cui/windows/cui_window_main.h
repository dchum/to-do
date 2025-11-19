#pragma once

#include "cui_widget_box.h"

namespace cui
{
    class WindowMain final: public WidgetBox
    {
    public:
        WindowMain( Widget * parent = nullptr );
    };
}