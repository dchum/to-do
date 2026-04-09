#include "model.h"

core::Model::Model()
    :board_(),
    executor_(board_)
{
}

void core::Model::update(CommandMessage cmd)
{
    std::visit( executor_, cmd.payload );
}

void core::Model::ModelExecutor::operator()(const CmdStart &cmd)
{
    board_.Init( cmd.name_board );
}

void core::Model::ModelExecutor::operator()(const CmdAddNewTask &cmd)
{
    board_.AddNewTask( cmd.name_new_task );
}
