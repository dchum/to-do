#include "model_task.h"

#include <algorithm>
#include <chrono>  /* для учета времени */
#include <ctime>


namespace core
{

TaskID Task::id = 0;
    
Task::Task(const std::string &name, STATUS_TASK status)
    : id_(id++), name_(name), description_(""), 
         status_task_(status), ending_date_({0})
{
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm *timeInfo = std::localtime(&currentTime);

    creation_date_ = {
        .hours   = timeInfo->tm_hour,
        .minutes = timeInfo->tm_min,
        .day     = timeInfo->tm_mday,
        .month   = timeInfo->tm_mon + 1, // tm_mon начинается с 0
        .year    = 1900 + timeInfo->tm_year,
    };
}

STATUS_TASK Task::set_status_task(STATUS_TASK attribute) noexcept
{
    status_task_ = attribute;

    return status_task_;
}

void Task::add_ending_date(data_t date) noexcept
{
    ending_date_ = date;
}

}


