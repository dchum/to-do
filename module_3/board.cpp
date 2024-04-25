#include "board.h"

Service_Class::Service_Class(const string &str)
    : _count_done_task(0), _name_level(str), _count_all_task(0)
{
    _tasks.reserve(COUNT_TASKS_IN_SERVICE_CLASS);
    _tasks.shrink_to_fit();
}

int Service_Class::count_all_task(void) const noexcept
{
    return _count_all_task;
}

int Service_Class::count_done_task(void) const noexcept
{
    return _count_done_task;
}

string Service_Class::name_level(void) const noexcept
{
    return _name_level;
}

STATUS Service_Class::remove_task(const string &name_task)
{
    vector<Task>::iterator it = find_if(_tasks.begin(), _tasks.end(),
                                        [&name_task](const Task &task)
                                        {
                                            return task.name() == name_task;
                                        });

    if (it != _tasks.end())
    {
        _tasks.erase(it);
        return STATUS::SUCCES;
    }
    return STATUS::FAILURE;
}

void Service_Class::search(const string &query)
{
    vector<string> name_tasks;
    name_tasks.reserve(_tasks.size());

    for(const auto& tmp : _tasks)
        name_tasks.push_back(tmp.name());

    search_server.AddDocument(name_tasks);

    for (const auto tmp : search_server.FindTopDocuments(query))
    {
        cout << " index: "            << tmp.index 
             << " comparable_words: " << tmp.comparable_words 
             << " relevance: "        << tmp.relevance 
        << endl; 
    }
}

void Service_Class::search_tag(const string &query)
{
    vector<string> tag_tasks;

    for(const auto& tmp : _tasks)
    {
        for (const auto& tag : tmp.get_tags())
        {
            tag_tasks.push_back(tag);
        }
    }

    search_server.AddDocument(tag_tasks);

    for (const auto tmp : search_server.FindTopDocuments(query))
    {
        cout << " index: "            << tmp.index 
             << " comparable_words: " << tmp.comparable_words 
             << " relevance: "        << tmp.relevance 
        << endl; 
    }
}

STATUS Service_Class::add_task(const string &name_task)
{
    vector<Task>::iterator it = find_if(_tasks.begin(), _tasks.end(),
                                        [&name_task](const Task &task)
                                        {
                                            return task.name() == name_task;
                                        });

    if (it == _tasks.end())
    {
        _tasks.push_back(Task{name_task}); // NOTE - проверить кол-во вызываемых констукторов
        return STATUS::SUCCES;
    }

    return STATUS::FAILURE;
}

void Service_Class::update(void)
{
    _count_all_task = _tasks.size();

    for (auto &tmp : _tasks)
    {
        if (STATUS::SUCCES == tmp.change_task_status(STATUS::INVARIABLY))
            _count_done_task++;
    }
}

Board::Board(int id) : _count_all_task(0),
                                _count_done_task(0),
                                _id(id)
{
    _service_classes.reserve(COUNT_SERVICE_CLASS_IN_BOARD);
    _service_classes.shrink_to_fit();

    _service_classes.push_back(Service_Class{STR(BACKLOG)});
    _service_classes.push_back(Service_Class{STR(IN_PROGRESS)});
    _service_classes.push_back(Service_Class{STR(DONE)});
}

STATUS Board::add_task_in_servise_class(const string &name_service_class, const string &name_task)
{
    vector<Service_Class>::iterator it;

    it = find_if(_service_classes.begin(), _service_classes.end(),
                 [&](const Service_Class &tmp)
                 {
                     return tmp.name_level() == name_service_class;
                 });

    if (it == _service_classes.end())
        return STATUS::FAILURE;

    return (*it).add_task(name_task);
}

STATUS Board::remove_task_in_servise_class(const string &name_service_class, const string &name_task)
{
    vector<Service_Class>::iterator it;

    it = find_if(_service_classes.begin(), _service_classes.end(),
                 [&](const Service_Class &tmp)
                 {
                     return tmp.name_level() == name_service_class;
                 });

    if (it != _service_classes.end())
        return (*it).remove_task(name_task);

    return STATUS::FAILURE;
}

int Board::count_all_task(void)
{
    update();
    return _count_all_task;
}

int Board::count_done_task(void)
{
    update();
    return _count_done_task;
}

int Board::count_servive_class(void)
{
    return _service_classes.size();
}

int Board::count_all_task_in_service_class(const string &name_service_class)
{
    vector<Service_Class>::iterator it;
    it = find_if(_service_classes.begin(), _service_classes.end(),
                 [&](const Service_Class tmp)
                 {
                     return tmp.name_level() == name_service_class;
                 });

    if (it != _service_classes.end())
        return (*it).count_all_task();
    else
        return 0;
}

void Board::search(const string &query)
{
    for(auto& tmp : _service_classes)
        tmp.search(query);
}

void Board::search_tag(const string &query)
{
    for(auto& tmp : _service_classes)
        tmp.search_tag(query);
}

int Board::count_done_task_in_service_class(const string &name_service_class)
{
    vector<Service_Class>::iterator it;
    it = find_if(_service_classes.begin(), _service_classes.end(),
                 [&](const Service_Class tmp)
                 {
                     return tmp.name_level() == name_service_class;
                 });

    if (it != _service_classes.end())
        return (*it).count_done_task();
    else
        return 0;
}

void Board::update(void)
{
    for (size_t i = 0; i < _service_classes.size(); i++)
    {
        _count_all_task += _service_classes[i].count_all_task();
        _count_done_task += _service_classes[i].count_done_task();
    }
}