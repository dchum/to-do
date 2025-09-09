#pragma once

#include "cui_widget.h"
#include "cui_widget_box.h"

namespace cui
{
    class Window: public Widget
    {
    protected:
        Window ( Widget* parent = nullptr );
    public:
        virtual ~Window()=default;

        void draw  ( void );
        void hide  ( void );

        WidgetBox wdgt_box;
    };
}