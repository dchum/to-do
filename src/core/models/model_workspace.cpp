#include "model_workspace.h"

void core::Board::Init(std::string name_board)
{
    name_board_ = name_board;
}

void core::Board::AddTask(std::string name_task)
{
    tasks_.push_back(name_task);
}
