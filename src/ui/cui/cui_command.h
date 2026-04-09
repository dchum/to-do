#pragma once

#include "message_ui2core.h"
#include "message_core2ui.h"

namespace cui
{

class Command
{
public:
    virtual ~Command() = default;

    virtual CommandMessage Execute( void ) = 0;
};

}//namespace cui