#include "handle_add_task.h"

void core::AddNewTask::Execute(WorkSpace &board, MessageAddNewTask& message)
{
    using namespace core;

    board.AddTask( message.name_new_task );
}