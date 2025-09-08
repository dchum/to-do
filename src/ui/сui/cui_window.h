#pragma once

#include "cui_widget.h"
#include "cui_widget_box.h"

namespace cui
{
    class Window: public Widget
    {
    public:
        Window ( Widget* parent = nullptr );
        virtual ~Window()=default;

        void draw  ( void );
        void hide  ( void );

        WidgetBox wdgtbox;
    };
}