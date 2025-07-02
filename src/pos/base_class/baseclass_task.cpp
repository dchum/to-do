#include "baseclass_task.h"

#include <algorithm>
#include <chrono>  /* для учета времени */
#include <ctime>


namespace pos
{
    
Task::Task(const std::string &name, const std::string &description, STATUS is_done, const data_t &ending_date)
        :lib::Task(), 
         _name(name), _description(description), 
         _status(is_done), _ending_date(ending_date)
{
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm *timeInfo = std::localtime(&currentTime);

    _creation_date = {
        .hours   = timeInfo->tm_hour,
        .minutes = timeInfo->tm_min,
        .day     = timeInfo->tm_mday,
        .month   = timeInfo->tm_mon + 1, // tm_mon начинается с 0
        .year    = 1900 + timeInfo->tm_year,
    };
}

STATUS Task::set_status(STATUS attribute) noexcept
{
    if ( attribute != STATUS::INVARIABLY ) 
        _status = attribute;

    return _status;
}

void Task::add_ending_date(data_t date) noexcept
{
    memcpy(&_ending_date, &date, sizeof(data_t));
}

}


