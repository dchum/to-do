/*****************************************************************************************************************************
[x]          - признак наличия метода/поля в коде
{x}          - признак наличия покрывающего теста для того или иного метода/поля
*опционально - обязательно к реализации, но использование класса возможно и без этого поля
   
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

    update:
    1) Реализовать возможность самому создавать классы обслуживания, настраивать какие классы будут отображаться по умолчанию
    2) Работа с тегами
    3) Поиск
****************************************************************************************************************************** */
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "baseclass_task.h"

#include "global_lib.h"


#define COUNT_TASKS_IN_SERVICE_CLASS 3
#define COUNT_SERVICE_CLASS_IN_BOARD 3


class Service_Class
{
private:
    int _count_done_task = 0,
        _count_all_task = 0;
    std::string _name_level = "";
    std::vector<Task> _tasks;
    SERVISE_CLASS _id;

public:
    // explicit Service_Class(SERVISE_CLASS id, );

    int count_all_task(void) const noexcept { return _count_all_task; };
    int count_all_task(void) noexcept       { return _count_all_task; };

    int count_done_task(void) const noexcept { return _count_done_task; };
    int count_done_task(void) noexcept       { return _count_done_task; };

    std::string name_level(void) const noexcept { return _name_level; }
    std::string name_level(void) noexcept       { return _name_level; }

    STATUS remove_task(const std::string &name_task);

    STATUS add_task(const std::string &name_task);

private:
    void update(void);
};


class Board
{
private:
    std::vector<Service_Class> _service_classes;
    int _count_done_task,
        _count_all_task,
        _id;

public:
    Board(int id); //FIXME нужен инициализатор для доски

    int count_all_task(void) const noexcept { return _count_all_task; }
    int count_all_task(void) noexcept       { return _count_all_task; }

    int count_done_task(void) const noexcept { return _count_done_task; }
    int count_done_task(void) noexcept       { return _count_done_task; }

    int count_servive_class(void) const noexcept { return _service_classes.size(); }
    int count_servive_class(void) noexcept       { return _service_classes.size(); }

    std::vector<Service_Class> get_service_classes() const noexcept { return _service_classes; }
    std::vector<Service_Class> get_service_classes() noexcept       { return _service_classes; }

    int count_all_task_in_service_class(const std::string &name_service_class);

    int count_done_task_in_service_class(const std::string &name_service_class);

private:
    void update(void);
};