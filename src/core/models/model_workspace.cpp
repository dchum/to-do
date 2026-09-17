#include "model_workspace.h"

#include <utility>

core::WorkSpaceID core::WorkSpace::id = 0;

core::WorkSpace::WorkSpace(const std::string &name_board)
:id_(id++), name_board_(name_board)
{
}

void core::WorkSpace::Init(const std::string &name_board)
{
    name_board_ = name_board;
}

void core::WorkSpace::AddTask( const std::string& name_task )
{
    tasks_.push_back(name_task);
}

void core::WorkSpace::AddTask(Task &&task)
{
    tasks_.emplace_back( std::move(task) );
}
