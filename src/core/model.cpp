#include "model.h"

std::optional<EventMessage> core::Model::ModelExecutor::handle(const CmdStart &cmd, Board &board)
{
    board.Init( cmd.name_board );
}

std::optional<EventMessage> core::Model::ModelExecutor::handle(const CmdAddNewTask &cmd, Board &board)
{
    board.AddNewTask( cmd.name_new_task );
    return EventMessage{ .id = 0, .payload = EventAddNewTask{.name_new_task = cmd.name_new_task} };
}

EventMessage core::Model::process(void)
{
    return events_[0];
}
