#include "handle_add_task.h"

void core::AddNewTask::Execute(Board &board, MessageAddNewTask& message)
{
    using namespace core;

    board.AddTask( message.name_new_task );
}