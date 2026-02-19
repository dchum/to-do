#pragma once

#include <string>

extern "C" 
{ 
#include "cdk/entry.h" 
#include "cdk/cdk_objs.h"
}

#include "cui_command.h"
#include "cui_screen.h"
#include "cui_lib.h"
#include "cui_widget.h"

namespace cui
{

class AddNewTask : public Command {
    Message title_;
    Message label_;

    Widget& target_;
    
public:
    AddNewTask( Widget& target, const std::string& title, const std::string& label);

    void Execute() override;
};

}//namespace cui