#pragma once

#include "cui_widget.h"
#include "cui_widget_box.h"

namespace cui
{
    class Window: public Widget
    {
        WidgetBox wdgt_box_;
    
    protected:
        Window ( Widget* parent = nullptr );
    public:
        virtual ~Window()=default;

        void draw  ( void );
        void hide  ( void );

        void OnAddChild   (Widget* child) override;
        void OnRemoveChild(Widget* child) override;
    };
}