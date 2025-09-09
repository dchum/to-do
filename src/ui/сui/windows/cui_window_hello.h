#pragma once

#include "cui_window.h"

namespace cui
{
    class WindowHello: public Window
    {
    public:
        WindowHello( Widget * parent = nullptr );

        void OnAddChild   (Widget* child) override;
        void OnRemoveChild(Widget* child) override;
    };
}