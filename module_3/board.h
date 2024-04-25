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
[x]{} поиск нужной задачи
[x]{} удалить задачу
[x]{} добавить задачу

******************************************************************************************************************************
    Класс "Доска" - Board. Используется в интерфейсах "Kanban". Состоит из классов обслуживания
    /*NOTE - Сейчас будет по умолчанию три класса обслуживания : Сделать, В работе, Готово (см task_lib.h).

    Поля класса:
    //NOTE -  v 1.0
[ ]  _name    : (string)                                                 -название доски
или  _id      : (int)                                                    -идентификатор доски
[ ]  _service_classes   : (структура данных для хранения Service_Class)  -все задачи, распределенные по классам

    Методы класса:
    //NOTE -  v 1.0
[x]{ } конструктор принимающий идентификатор доски
[x]{ } добавить/убрать задачу в _service_classes
[x]{ } получить кол-во используемых классов обслуживания для доски
[x]{ } получить кол-во всех/выполненнных задач в рамках одного класса обслуживания
[x]{ } получить кол-во всех/выполненнных задач всей доски
[x]{ } поиск задачи
[ ]{ } поиск среди всех задач по тегу /*TODO - реализовать поиск

    update:
    1) Реализовать возможность самому создавать классы обслуживания, настраивать какие классы будут отображаться по умолчанию

****************************************************************************************************************************** */
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "global_lib.h"
#include "task.h"
#include "str_switch.h"

#include "search/search.h"

#define COUNT_TASKS_IN_SERVICE_CLASS 3
#define COUNT_SERVICE_CLASS_IN_BOARD 3

using namespace std;

class Service_Class
{
private:
    int _count_done_task = 0,
        _count_all_task = 0;
    string _name_level = "";
    vector<Task> _tasks;

    SearchServer search_server;

public:
    explicit Service_Class(const string &str);

    int count_all_task(void) const noexcept;

    int count_done_task(void) const noexcept;

    string name_level(void) const noexcept;

    STATUS remove_task(const string &name_task);

    void search(const string& query);//STUB - пока неизвестно, какой должен быть вывод на запрос

    void search_tag(const string& query);//STUB - пока неизвестно, какой должен быть вывод на запрос

    STATUS add_task(const string &name_task);

private:
    void update(void);
};


class Board
{
private:
    vector<Service_Class> _service_classes;
    int _count_done_task,
        _count_all_task,
        _id;

public:
    explicit Board(int id);

    STATUS add_task_in_servise_class(const string &name_service_class, const string &name_task);

    STATUS remove_task_in_servise_class(const string &name_service_class, const string &name_task);

    int count_all_task(void);

    int count_done_task(void);

    int count_servive_class(void);

    int count_all_task_in_service_class(const string &name_service_class);

    void search(const string& query);//STUB - пока неизвестно, какой должен быть вывод на запрос

    void search_tag(const string& query);//STUB - пока неизвестно, какой должен быть вывод на запрос

    int count_done_task_in_service_class(const string &name_service_class);

private:
    void update(void);
};