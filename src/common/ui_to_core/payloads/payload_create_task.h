#pragma once

#include <string>

#include "commands_id.h"
#include "payload_ui.h"


struct MessageAddNewTask{
    std::string name_new_task;
};

template <>
struct MessageUI<CommandId::CreateTask> {
    using type = MessageAddNewTask;
};