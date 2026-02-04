#pragma once

#include "cui_widget_box.h"

namespace cui
{

class Window: public WidgetBox
{
protected:
    Window ( Widget* parent = nullptr )
    :WidgetBox(parent)
    {

    }
    
public:
    virtual ~Window()=default;
    
    virtual void init( void ) = 0;

    virtual void input( char ) {}
};

}