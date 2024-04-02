/*****************************************************************************************************************************
    Класс "Класс обслуживания" - Service_Class. Представляет собой совокупность задач, находящихся на одном логическом уровне
    в канбан-доске.
    //NOTE - v 1.0
    Поля класса:
[]  _name_level      : (string)                           -название логического уровня
[]  _count_done_task : (int)                              -кол-во выполненных задач в текущем уровне
[]  _tasks           : (vector<Task>)                     -все задачи

    Методы класса:
    //NOTE -  v 1.0
[x]{} получить кол-во задач
[x]{} получить кол-во выполненных задач
[x]{} получить название логического уровня
[]{} поиск нужной задачи /*TODO - реализовать поиск
[x]{} удалить задачу
[x]{} добавить задачу

******************************************************************************************************************************
    Класс "Доска" - Board. Используется в интерфейсах "Kanban". Состоит из классов обслуживания
    /*NOTE - Сейчас будет по умолчанию три класса обслуживания : Сделать, В работе, Готово (см task_lib.h). В будущем реализовать
    возможность самому создавать классы обслуживания, настраивать какие классы будут отображаться по умолчанию

    Поля класса:
    //NOTE -  v 1.0
[ ]  _name    : (string)                                  -название доски
[ ]  _chapter : ?                                         -совокупность Service_Class
[ ]  _tasks   : (структура данных для хранения _chapter)  -все задачи, распределенные по классам

    Методы класса:
    //NOTE -  v 1.0
[ ]{ } конструктор по умолчанию
[ ]{ } добавить/убрать задачу в _chapter
[ ]{ } получить кол-во задач в _chapter
[ ]{ } получить кол-во используемых классов обслуживания для доски
[ ]{ } получить кол-во всех/выполненнных задач в рамках одного класса обслуживания
[ ]{ } поиск задачи /*TODO - реализовать поиск
[ ]{ } поиск среди всех задач по тегу /*TODO - реализовать поиск

****************************************************************************************************************************** */
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "global_lib.h"
#include "task.h"
#include "str_switch.h"

#define COUNT_TASKS 3

using namespace std;

class Service_Class
{
public:
    explicit Service_Class(const string &str)
        : _count_done_task(0), _name_level(str), _count_task(0)
    {
        tasks.reserve(COUNT_TASKS);
    }

    int get_count_task(void)
    {
        update();
        return _count_task;
    }

    int get_count_done_task(void)
    {
        update();
        return _count_done_task;
    }

    string get_name_level(void)
    {
        update();
        return _name_level;
    }

    STATUS remove_task(const string &name_task)
    {
        update();

        vector<Task>::iterator it = find_if(tasks.begin(), tasks.end(),
                                            [&name_task](const Task &task)
                                            { return task.get_name() == name_task; });

        if (it != tasks.end())
        {
            tasks.erase(it);
            return STATUS::SUCCES;
        }
        return STATUS::FAILURE;
    }

    STATUS add_task(const string &name_task)
    {
        update();

        vector<Task>::iterator it = find_if(tasks.begin(), tasks.end(),
                                            [&name_task](const Task &task)
                                            { return task.get_name() == name_task; });

        if (it == tasks.end())
        {
            tasks.push_back(Task(name_task)); // NOTE - проверить кол-во вызываемых констукторов
            return STATUS::SUCCES;
        }

        return STATUS::FAILURE;
    }

private:
    int _count_done_task = 0,
        _count_task = 0;
    string _name_level = "";
    vector<Task> tasks;

    void update(void)
    {
        _count_task = tasks.size();

        for (auto &tmp : tasks)
        {
            if (STATUS::SUCCES == tmp.change_task_status(STATUS::INVARIABLY))
                _count_done_task++;
        }
    }
};

class Board
{
};
