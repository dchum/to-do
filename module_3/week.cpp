#include "week.h"

#include <cassert>
#include <stdexcept>
#include <iostream>
#include <numeric>

Week::Week()
{
    _days_week.reserve(static_cast<size_t>(WEEKDAY::NUM_DAY_WEEK));
    _days_week.shrink_to_fit();
}

/**Кол-во выполненных задач */
int Week::count_done_task(void) noexcept
{
    update();
    assert(_count_done_task >= 0);
    return _count_done_task;
}

/**Кол-во всех задач */
int Week::count_all_task(void) noexcept
{
    update();
    assert(_count_all_task >= 0);
    return _count_all_task;
}

/**Кол-во невыполненных задач */
int Week::count_notready_task(void) noexcept
{
    update();
    assert((_count_all_task - _count_done_task) >= 0);
    return _count_all_task - _count_done_task;
}

/**Поиск задачи в недели */
std::vector<std::pair<Day, Task>> Week::task_search(const string &name_task)
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
std::vector<std::pair<Day, Task>> Week::tag_search(const string &name_tag)
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

/**Обновляем текущую статистику */
void Week::update(void)
{
    _count_all_task = accumulate(_days_week.begin(), _days_week.end(), 0,
                                 [](int curr_sum, const Day &day)
                                 {
                                     return  curr_sum + day.count_all_task();
                                 });

    _count_done_task = accumulate(_days_week.begin(), _days_week.end(), 0,
                                  [](int curr_sum, Day &day)
                                  {
                                      return  curr_sum + day.count_done_task();
                                  });
}