#pragma once

#include <string>

#include "cui_command.h"

namespace cui
{

class NoneCommand : public Command {
public:
    NoneCommand(  ) : Command() {}
    CommandMessage Execute() override {};
};

}//namespace cui