#pragma once

namespace ui
{

class Ui_Imp
{
public:
    Ui_Imp() = default;
    virtual ~Ui_Imp() {}

    virtual void init ( void ) = 0;
    virtual void start( void ) = 0;
    virtual void end  ( void ) = 0;
};

}