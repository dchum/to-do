// // /*****************************************************************************************************************************
// // [x]          - признак наличия метода/поля в коде
// // {x}          - признак наличия покрывающего теста для того или иного метода/поля
// // *опционально - обязательно к реализации, но использование класса возможно и без этого поля
   
// //     Класс "Класс обслуживания" - Column. Представляет собой совокупность задач, находящихся на одном логическом уровне
// //     в канбан-доске.
// //     //NOTE - v 1.0
// //     Поля класса:
// // []  _name_level      : (string)                           -название логического уровня
// // []  _count_done_task : (int)                              -кол-во выполненных задач в текущем уровне
// // []  _tasks           : (vector<Task>)                     -все задачи

// //     Методы класса:
// //     //NOTE -  v 1.0
// // [x]{} получить кол-во задач
// // [x]{} получить кол-во выполненных задач
// // [x]{} получить название логического уровня
// // [x]{} удалить задачу
// // [x]{} добавить задачу

// // ******************************************************************************************************************************
// //     Класс "Доска" - Board. Используется в интерфейсах "Kanban". Состоит из классов обслуживания
// //     /*NOTE - Сейчас будет по умолчанию три класса обслуживания : Сделать, В работе, Готово (см task_lib.h).

// //     Поля класса:
// //     //NOTE -  v 1.0
// // [x]  _name    : (string)                                                 -название доски
// // или  _id      : (int)                                                    -идентификатор доски
// // [x]  _columns   : (структура данных для хранения Column)  -все задачи, распределенные по классам

// //     Методы класса:
// //     //NOTE -  v 1.0
// // [x]{ } конструктор принимающий идентификатор доски
// // [x]{ } получить кол-во используемых классов обслуживания для доски
// // [x]{ } получить кол-во всех/выполненнных задач в рамках одного класса обслуживания
// // [x]{ } получить кол-во всех/выполненнных задач всей доски

// //     update:
// //     1) Реализовать возможность самому создавать классы обслуживания, настраивать какие классы будут отображаться по умолчанию
// //     2) Работа с тегами
// //     3) Поиск
// // ****************************************************************************************************************************** */
#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "model_task.h"


namespace core
{
#if 0 //пока без деления на группы задач, просто собираем все задачи подряд
class Column
{
private:
    int _count_done_task = 0,
        _count_all_task = 0;
    std::string _name_level = "";
    std::vector<core::Task> _tasks;

public:
    Column( std::string name = "" );

    /*! @brief Кол-во задач в классе обслуживания */
    int count_all_task(void) const noexcept   { return _count_all_task; };

    /*! @brief Кол-во решенных задач в классе обслуживания  */
    int count_done_task(void) const noexcept   { return _count_done_task; };

    /*! @brief Наименование класса обслуживания */
    std::string name_level(void) const noexcept   { return _name_level; }

    /*! @brief Добавить новую задачу */
    STATUS add_task(const std::string &name_task)  ;

    /*! @brief Убрать задачу */
    STATUS remove_task(const std::string &name_task)  ;

private:
    /*! @brief Обновление состояния */
    void update(void);
};


inline bool operator<(const core::Column &lhs, const core::Column &rhs)
{
    return std::lexicographical_compare(lhs.name_level().begin(), lhs.name_level().end(), rhs.name_level().begin(), rhs.name_level().end());
}

#endif

class Board
{
private:
    std::vector<Task> tasks_;

    std::string name_board_;

public:
    Board() = default;

    // /*! @brief Кол-во задач на доске */
    // int count_all_task(void) const noexcept { return _count_all_task; }

    // /*! @brief Кол-во решенных задач на доске */
    // int count_done_task(void) const noexcept { return _count_done_task; }

    // /*! @brief Кол-во классов обслуживания на доске */
    // int count_service_class(void) const noexcept { return _columns.size(); }

    /*! @brief Получить доступные классы обслуживания  */
    // std::vector<Column> get_columnes() const noexcept { return _columns; }

    // /*! @brief Кол-во задач в рамках конкретного класса обсуживания */
    // int count_all_task_in_column(const std::string &name_column);

    // /*! @brief Кол-во решенных задач в рамках конкретного класса обслуживния */
    // int count_done_task_in_column(const std::string &name_column);

public:
    void Init( std::string name_board );
    void AddNewTask( std::string name_task );
};

}