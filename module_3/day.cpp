#include "day.h"

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <chrono>  /* для учета времени */
#include <ctime>

Day::Day()
{
    auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm *timeInfo = localtime(&currentTime);

    _date = {
        .hours = -1,
        .minutes = -1,
        .day = timeInfo->tm_mday,
        .month = timeInfo->tm_mon + 1, // tm_mon начинается с 0
        .year = -1,
    };
}

pair<int, int> Day::date(void)
{
    return make_pair(_date.day, _date.month);
}

int Day::count_done_task(void)
{
    _count_done_task = 0;
    for (auto tmp : _set_task)
    {
        if (tmp.change_task_status(STATUS::INVARIABLY) == STATUS::SUCCES)
            _count_done_task++;
    }

    return _count_done_task;
}

int Day::count_all_task(void) const
{
    return _set_task.size();
}

STATUS Day::add_new_task(Task task)
{
    auto ret = _set_task.insert(task);

    return ret.second ? STATUS::SUCCES : STATUS::FAILURE;
}

STATUS Day::delete_task(const string &name_task)
{
    int ret = 0;

    try
    {
        const Task &task = get_task(name_task);
        ret = _set_task.erase(task);
    }
    catch (const std::logic_error &e)
    {
        std::cerr << e.what() << '\n';
        return STATUS::FAILURE;
    }

    return ret != 0 ? STATUS::SUCCES : STATUS::FAILURE;
}

const Task& Day::get_task(const string &name_task) const
{
    set<Task>::iterator it;

    it = find_if(_set_task.begin(), _set_task.end(), 
                [&](const Task& tmp)
                {
                    return tmp.name() == name_task;
                });

    if ( it != _set_task.end() )
        return (*it);
    else
        throw logic_error("ERROR: There is no task - task()\n");
}