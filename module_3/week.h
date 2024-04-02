/*****************************************************************************************************************************
    Класс "Неделя" - Week. Используется в интерфейсах "Еженедельное планирование"
    Поля класса:
    //NOTE -  v 1.0
[x] _count_done_task : int                      - кол-во выполненных задач на неделе
[x] _count_all_task  : int                      - кол-во всех задач на неделе
[x] _days_week       : _days_week[NUM_DAY_WEEK]  - вектор дней недели

    Методы класса:
    //NOTE -  v 1.0
[x]{ } поиск по тегу   - на выходе выдать дни и задачи в этом дне
[x]{ } поиск по задаче - на выходе выдать день и задачу
[x]{ } выдать число всех/выпо/невыполненных задач
    update:
    1. Сейчас поиск идет по 100% совпадению. Реализовать позже выдачу результатов и по частичному совпадению: совпали некоторые
    слова
    2. Реализовать параллельный поиск
****************************************************************************************************************************** */

#pragma once
#include <vector>
#include <utility>
#include <cassert>

#include "day.h"
#include "global_lib.h"

using namespace std;

class Week
{
private:
    int _count_done_task = 0,
        _count_all_task = 0;

    vector<Day> _days_week;

    /**Обновляем текущую статистику */
    void update(void)
    {
        for (auto &task : _days_week)
        {
            _count_all_task += task.get_count_task();
            _count_done_task += task.get_count_task_done();
        }
    }

public:
    Week()
    {
        _days_week.reserve(static_cast<size_t>(WEEKDAY::NUM_DAY_WEEK));
    }

    /**Кол-во выполненных задач */
    int get_count_done_task(void) noexcept
    {
        update();
        assert(_count_done_task >= 0);
        return _count_done_task;
    }

    /**Кол-во всех задач */
    int get_count_all_task(void) noexcept
    {
        update();
        assert(_count_all_task >= 0);
        return _count_all_task;
    }

    /**Кол-во невыполненных задач */
    int get_count_notready_task(void) noexcept
    {
        update();
        assert((_count_all_task - _count_done_task) >= 0);
        return _count_all_task - _count_done_task;
    }

    /**Поиск задачи в недели */
    std::vector<std::pair<Day, Task>> task_search(const string &name_task)
    {
        std::vector<std::pair<Day, Task>> found_tasks;
        for (const auto &_day : _days_week)
        {
            try
            {
                Task task = _day.get_task(name_task);
                found_tasks.push_back(std::make_pair(_day, task));
            }
            catch (const std::logic_error &e)
            {
                std::cerr << "ERROR: task not found\n";
            }
        }
        return found_tasks;
    }

    /**Поиск задачи по тегу среди недели */
    std::vector<std::pair<Day, Task>> tag_search(const string &name_tag)
    {
        std::vector<std::pair<Day, Task>> found_tasks;
        for (const auto &_day : _days_week)
        {
            try
            {
                Task task = _day.get_task(name_tag);
                found_tasks.push_back(std::make_pair(_day, task));
            }
            catch (const std::logic_error &e)
            {
                std::cerr << "ERROR: task not found\n";
            }
        }
        return found_tasks;
    }
};