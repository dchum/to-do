#include "model_service.h"

#include <algorithm>
#include <numeric>


namespace core
{
    Column::Column(std::string name)
    :_count_done_task(0), _count_all_task(0),
     _name_level(name)
{
}

void Column::AttachTask(Task & task)
{
    tasks_.push_back( &task );
}

void Column::DetachTask(Task &task)
{
    auto it = std::remove_if(tasks_.begin(), tasks_.end(),
                             [&task](const Task *t) {
                                 return task.name() == t->name();
                             });
    tasks_.erase(it, tasks_.end());
}

void Column::update(void)
{
    _count_all_task = tasks_.size();

    _count_done_task = std::count_if(tasks_.begin(), tasks_.end(), 
                        [](const Task *task)
                        { return task->status() == STATUS::SUCCES; });
}



void Board::Init(std::string name_board)
{
    name_board_ = name_board;
}

void Board::AddTask(std::string name_task)
{
    tasks_.push_back(name_task);
}

}//namespace core