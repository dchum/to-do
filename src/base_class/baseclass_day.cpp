#include "baseclass_day.h"

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <chrono>  /* для учета времени */
#include <ctime>

Day::Day()
{
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    tm *timeInfo = localtime(&currentTime);

    memset(&_date, -1, sizeof(_date));
    _date = { .day = timeInfo->tm_mday, .month = timeInfo->tm_mon + 1, /* tm_mon начинается с 0 */ };
}

int Day::count_done_task(void)
{
    _count_done_task = 0;
    for (auto tmp : _tasks_day)
    {
        if (tmp.change_task_status(STATUS::INVARIABLY) == STATUS::SUCCES)
            _count_done_task++;
    }

    return _count_done_task;
}

int Day::count_all_task(void) const
{
    return _tasks_day.size();
}

STATUS Day::add_new_task(Task task)
{
    auto ret = _tasks_day.insert(task);

    return ret.second ? STATUS::SUCCES : STATUS::FAILURE;
}

STATUS Day::delete_task(const std::string &name_task)
{
    int ret = 0;

    try
    {
        const Task &task = get_task(name_task);
        ret = _tasks_day.erase(task);
    }
    catch (const std::logic_error &e)
    {
        std::cerr << e.what() << '\n';
        return STATUS::FAILURE;
    }

    return ret != 0 ? STATUS::SUCCES : STATUS::FAILURE;
}


const Task& Day::get_task(const std::string &name_task) const
{
    std::set<Task>::iterator it;

    it = find_if(_tasks_day.begin(), _tasks_day.end(), 
                [&](const Task& tmp) { return tmp.name() == name_task; });

    if ( it != _tasks_day.end() )
        return (*it);
    else
        throw std::logic_error("ERROR: There is no task - task()\n");
}