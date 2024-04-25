#include "task.h"

#include <algorithm>
#include <chrono>  /* для учета времени */
#include <ctime>
#include <stdexcept>

Task::Task(const std::string &name, const std::string &description, STATUS is_done, float progress,
        const data_t &ending_date,
        const std::set<std::string> &tags)
    : _name(name),
        _description(description),
        _is_done(is_done),
        _progress(progress),
        _ending_date(ending_date),
        _tags(tags)
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


STATUS Task::change_items_status(const string &description, STATUS attribute)
{

    list<SUB_ITEMS>::iterator it;

    it = find_if(_sub_items.begin(), _sub_items.end(),
                [&](const SUB_ITEMS& tmp)
                {
                    return tmp.first == description;
                });
    
    if ( it == _sub_items.end() )
        throw logic_error("ERROR: The item is missing - change_items_status\n");

    switch (attribute)
    {
    case STATUS::SUCCES:
        it->second = STATUS::SUCCES;
        break;
    case STATUS::FAILURE:
        it->second = STATUS::FAILURE;
        break;
    case STATUS::INVARIABLY:
    default:
        break;
    }
    return it->second;
}


int Task::size_sub_items(void)
{
    return _sub_items.size();
}


STATUS Task::add_tag(const std::string &tag)
{
    auto ret = _tags.insert(tag);

    return ret.second ? STATUS::SUCCES : STATUS::FAILURE;
}


STATUS Task::remove_tag(const std::string &tag)
{
    auto ret = _tags.erase(tag);

    return ret == 1 ? STATUS::SUCCES : STATUS::FAILURE;
}


STATUS Task::have_tag(const std::string &tag)
{
    return _tags.count(tag) ? STATUS::SUCCES : STATUS::FAILURE;
}

std::set<std::string> Task::get_tags(void) const
{
    return _tags;
}

void Task::add_items(string &items)
{
    _sub_items.push_back(std::make_pair(items, STATUS::FAILURE));
}


STATUS Task::delete_items(const string &description)
{
    list<SUB_ITEMS>::iterator it;

    it = find_if(_sub_items.begin(), _sub_items.end(),
                [&](const SUB_ITEMS& tmp)
                {
                    return tmp.first == description;
                });

    auto ret = _sub_items.erase(it);

    return it != _sub_items.end() ? STATUS::SUCCES : STATUS::FAILURE;
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


void Task::update_progress(void)
{
    int number_completed_items = 0;
    for (const auto &[name, is_done] : _sub_items)
    {
        if (is_done == STATUS::SUCCES)
            number_completed_items++;
    }
    _progress = (_sub_items.size() == 0) ? 0 : (number_completed_items * 1.) / (_sub_items.size() * 1.);
}
