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

#include "commandmessage.h"

namespace cui
{

class AddNewTask {
    Message title_{ "<C>New task" };
    Message label_{ "name task:"  };

public:
    void Execute( CUIScreen& screen, std::queue<MessagePayload>& queue_message_ui_  );
};

template <>
struct CommandImpl<CommandId::CreateTask> {
    using type = AddNewTask;
};

}//namespace cui