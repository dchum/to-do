#include "baseclass_service.h"

#include <algorithm>
#include <numeric>


namespace pos
{

Service_Class::Service_Class(std::string name, SERVISE_CLASS id)
    : lib::Service_Class(),
    _count_done_task(0), _count_all_task(0),
    _name_level(name), _id(id)
{
    // _tasks.reserve(COUNT_TASKS_IN_SERVICE_CLASS);
    // _tasks.shrink_to_fit();
}

STATUS Service_Class::remove_task(const std::string &name_task)
{
    // std::vector<Task>::iterator it = std::find_if(_tasks.begin(), _tasks.end(),
    //                                                 [&name_task](const Task &task)
    //                                                 { return task.name() == name_task; });
    // if (it != _tasks.end())
    // {
    //     _tasks.erase(it);
    //     return STATUS::SUCCES;
    // }
    // return STATUS::FAIL;
}

STATUS Service_Class::add_task(const std::string &name_task)
{
    // std::vector<Task>::iterator it = std::find_if(_tasks.begin(), _tasks.end(),
    //                                                 [&name_task](const Task &task)
    //                                                 { return task.name() == name_task; });

    // if (it == _tasks.end())
    // {
    //     _tasks.push_back(Task{name_task}); // NOTE - проверить кол-во вызываемых констукторов
    //     return STATUS::SUCCES;
    // }

    // return STATUS::FAIL;
}

void Service_Class::update(void)
{
    _count_all_task = _tasks.size();

    _count_done_task = std::count_if(_tasks.begin(), _tasks.end(), 
                        [](const Task &task)
                        { return task.status() == STATUS::SUCCES; });
}

}




// Board::Board(std::string name, int id) 
//         : _count_all_task(0),
//         _count_done_task(0),
//         _id(id)
// {
//     _service_classes.reserve(COUNT_SERVICE_CLASS_IN_BOARD);
//     _service_classes.shrink_to_fit();

//     _service_classes.push_back(Service_Class{ STR(BACKLOG),     BACKLOG     });
//     _service_classes.push_back(Service_Class{ STR(IN_PROGRESS), IN_PROGRESS });
//     _service_classes.push_back(Service_Class{ STR(DONE),        DONE        });
// }

// int Board::count_all_task_in_service_class(const std::string &name_service_class)
// {
//     auto it = std::find_if(_service_classes.begin(), _service_classes.end(),
//                           [&](const Service_Class tmp) { return tmp.name_level() == name_service_class; });

//     if (it != _service_classes.end())
//         return (*it).count_all_task();
//     else
//         return 0;
// }

// int Board::count_done_task_in_service_class(const std::string &name_service_class)
// {
//     auto it = std::find_if(_service_classes.begin(), _service_classes.end(),
//                           [&](const Service_Class tmp) { return tmp.name_level() == name_service_class; });

//     if (it != _service_classes.end())
//         return (*it).count_done_task();
//     else
//         return 0;
// }

// void Board::update(void)
// {
//     _count_all_task = std::accumulate(_service_classes.begin(), _service_classes.end(), 0,
//                                       [](int accum, const Service_Class& tmp) { return accum + tmp.count_all_task(); });

//     _count_done_task = std::accumulate(_service_classes.begin(), _service_classes.end(), 0,
//                                       [](int accum, const Service_Class& tmp) { return accum + tmp.count_done_task(); });
// }