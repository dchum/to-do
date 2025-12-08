#pragma once

#include "cui_window.h"

namespace cui
{
    class WindowMain final: public Window
    {
    public:
        WindowMain( Widget * parent = nullptr );

        void init() override;

        void draw() override;
    };
}