#pragma once

#include <memory>
#include <vector>
#include <map>

#include "cui_container.h"
#include "cui_command.h"

namespace cui
{

class Window: public Container
{
protected:
    virtual cui::Command& get_command_binding(unsigned int key) = 0;

public:

    Window ( CUIScreen& screen ) :Container(screen) { }

    virtual ~Window()=default;
    
    virtual void init( void ) = 0;

    virtual CommandMessage update( uint ) = 0;
    virtual void process( EventMessage event ) = 0;
};//cui_window

}