#include "model_service.h"

#include <algorithm>
#include <numeric>


namespace core
{
#if 0
    Column::Column(std::string name)
    :
    _count_done_task(0), _count_all_task(0),
    _name_level(name)
{
}

STATUS Column::remove_task(const std::string &name_task)
{
    std::vector<Task>::iterator it = std::find_if(_tasks.begin(), _tasks.end(),
                                                    [&name_task](const Task &task)
                                                    { return task.name() == name_task; });
    if (it != _tasks.end())
    {
        _tasks.erase(it);
        return STATUS::SUCCES;
    }
    return STATUS::FAIL;
}

STATUS Column::add_task(const std::string &name_task)
{
    std::vector<Task>::iterator it = std::find_if(_tasks.begin(), _tasks.end(),
                                                    [&name_task](const Task &task)
                                                    { return task.name() == name_task; });

    if (it == _tasks.end())
    {
        _tasks.push_back(Task{name_task}); // NOTE - проверить кол-во вызываемых констукторов
        return STATUS::SUCCES;
    }

    return STATUS::FAIL;
}

void Column::update(void)
{
    _count_all_task = _tasks.size();

    _count_done_task = std::count_if(_tasks.begin(), _tasks.end(), 
                        [](const Task &task)
                        { return task.status() == STATUS::SUCCES; });
}


#endif

void Board::Init(std::string name_board)
{
    name_board_ = name_board;
}

void Board::AddNewTask(std::string name_task)
{
    tasks_.push_back(name_task);
}

}//namespace core