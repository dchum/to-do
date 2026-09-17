// ******************************************************************************************************************************
//     Класс "Рабочее пространство" - Workspace. Используется в интерфейсах "Kanban". Состоит из классов обслуживания

//     Поля класса:
//     //NOTE -  v 1.0
// [x]  _name    : (string)                                                 -название доски
// или  _id      : (int)                                                    -идентификатор доски
// [x]  _columns : (структура данных для хранения Column)  -все задачи, распределенные по классам

//     Методы класса:
//     //NOTE -  v 1.0
// [x]{ } конструктор принимающий идентификатор доски
// [x]{ } получить кол-во используемых классов обслуживания для доски
// [x]{ } получить кол-во всех/выполненнных задач в рамках одного класса обслуживания
// [x]{ } получить кол-во всех/выполненнных задач всей доски

//     update:
//     1) Реализовать возможность самому создавать классы обслуживания, настраивать какие классы будут отображаться по умолчанию
//     2) Работа с тегами
//     3) Поиск
// ****************************************************************************************************************************** */
#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "model_task.h"
#include "model_column.h"


namespace core
{

using WorkSpaceID = std::uint64_t;

class WorkSpace
{
    static WorkSpaceID id;
private:
    WorkSpaceID id_;

    std::vector<Column> group_tasks_;
    std::vector<Task> tasks_;
    std::string name_board_;

public:
    WorkSpace( const std::string& name_board );

    void Init( const std::string& name_board );
    void AddTask( const std::string& name_task );
    void AddTask( Task&& task );
};

}