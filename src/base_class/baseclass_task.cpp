#include "baseclass_task.h"

#include <algorithm>
#include <chrono>  /* для учета времени */
#include <ctime>
#include <stdexcept>

Task::Task(const std::string &name, const std::string &description, STATUS is_done,
        const data_t &ending_date)
        :_name(name),
        _description(description),
        _is_done(is_done),
        _ending_date(ending_date)
{
    _count_items = 0;

    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm *timeInfo = std::localtime(&currentTime);

    _creation_date = {
        .hours = timeInfo->tm_hour,
        .minutes = timeInfo->tm_min,
        .day = timeInfo->tm_mday,
        .month = timeInfo->tm_mon + 1, // tm_mon начинается с 0
        .year = 1900 + timeInfo->tm_year,
    };
}

std::string Task::name(void) const
{
    return _name;
}


std::string Task::description(void) const
{
    return _description;
}


float Task::progress(void)
{
    update_progress();
    return _progress;
}


STATUS Task::set_name_task(const string& name_task)
{
    _name = name_task;
    return STATUS::SUCCES;
}


STATUS Task::set_description_task(const string& description_task)
{
    _description = description_task;
    return STATUS::SUCCES;
}


STATUS Task::change_task_status(STATUS attribute)
{
    switch (attribute)
    {
    case STATUS::SUCCES:
        _is_done = STATUS::SUCCES;
        break;
    case STATUS::FAILURE:
        _is_done = STATUS::FAILURE;
        break;
    case STATUS::INVARIABLY:
    default:
        break;
    }
    return _is_done;
}

void Task::add_ending_date(data_t date)
{
    _ending_date.day = date.day;
    _ending_date.hours = date.hours;
    _ending_date.minutes = date.minutes;
    _ending_date.month = date.month;
    _ending_date.year = date.year;
}


void Task::delete_ending_date(void)
{
    _ending_date = {.hours = 0, .minutes = 0, .day = 0, .month = 0, .year = 0};
}

