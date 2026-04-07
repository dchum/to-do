#pragma once

#include <string>

extern "C" 
{ 
#include "cdk/entry.h" 
#include "cdk/cdk_objs.h"
}

#include "cui_screen.h"
#include "cui_lib.h"
#include "cui_widget.h"
#include "cui_command.h"

namespace cui
{

class AddNewTask : public Command {
    Message title_;
    Message label_;

    CUIScreen& screen_;
    
public:
    AddNewTask( CUIScreen& screen );

    CommandMessage Execute() override;
};

}//namespace cui