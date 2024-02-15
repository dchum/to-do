/*****************************************************************************************************************************
    Класс "День" - Day. Используется в интерфейсах "Еженедельное планирование"
    Поля класса:
    //NOTE -  v 1.0
[x]  _set_task          : set<int, Task>            - список всех задач Task для этого дня
[x]  _date              : date_t                    - день, месяц
[x]  _count_task_done   : int                       - кол-во выполненных задач в дне

    Методы класса:
    //NOTE -  v 1.0
[x]{ } констуктор по умолчанию
[x]{ } получить нужную задачу
[x]{ } удалить/добавить задачу
[x]{ } получить кол-во выполненных задач
[x]{ } получить дату для дня (день, месяц)

//TODO - возможно появится необходимость реализовать доступ по итераторам для for range цикла
****************************************************************************************************************************** */

#pragma once

#include <set>
#include <utility>
#include <stdexcept>
#include <iostream>

#include "task.h"
#include "task_lib.h"

using namespace std;

class Day
{
private:
    int _count_task_done = 0;
    data_t date = {.hours = -1, .minutes = -1, .day = 0, .month = 0, .year = 0};

    set<Task> _set_task;

public:
    Day()
    {
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm* timeInfo = std::localtime(&currentTime);
            
        date = {
            .hours   = -1,
            .minutes = -1,
            .day     = timeInfo->tm_mday,
            .month   = timeInfo->tm_mon + 1, // tm_mon начинается с 0
            .year    = -1,
        };

    }

    pair<int, int> get_date(void)
    {
        return make_pair(date.day, date.month);
    }

    int get_count_task_done(void)
    {
        _count_task_done = 0;
        for (auto tmp : _set_task)
        {
            if (tmp.change_task_status(ATTRIBUTE_TASK::INVARIABLY) == STATUS::SUCCES)
                _count_task_done++;
        }

        return _count_task_done;
    }

    STATUS add_new_task(Task task)
    {
        auto ret = _set_task.insert(task);

        return ret.second ? STATUS::SUCCES : STATUS::FAILURE;
    }

    STATUS delete_task(const string &name_task)
    {
        int ret = 0;

        try
        {
            const Task &task = get_task(name_task);
            ret = _set_task.erase(task);
        }
        catch(const std::logic_error& e)
        {
            std::cerr << e.what() << '\n';
            return STATUS::FAILURE;
        }
        
        return ret != 0 ? STATUS::SUCCES : STATUS::FAILURE;
    }

    const Task &get_task(const string &name_task)
    {
        for (const auto &tmp : _set_task)
        {
            if (tmp.get_name() == name_task)
            {
                return tmp;
            }
        }
        throw logic_error("ERROR: There is no task - get_task\n");
    }
};