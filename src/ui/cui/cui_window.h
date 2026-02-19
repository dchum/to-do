#pragma once

#include <functional>
#include <vector>
#include <map>

#include "cui_container.h"

namespace cui
{

class Window: public Container
{
public:

    Window ( CUIScreen& screen )
    :Container(screen)
    {

    }

    virtual ~Window()=default;
    
    virtual void init( void ) = 0;

};//cui_window

}