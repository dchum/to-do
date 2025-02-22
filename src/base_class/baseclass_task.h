/******************************************************************************************************************************************
[x]          - признак наличия метода/поля в коде
{x}          - признак наличия покрывающего теста для того или иного метода/поля
*опционально - обязательно к реализации, но использование класса возможно и без этого поля

    Класс "Задача" - Task. Используется в интерфейсах "Еженедельное планирование" и "Проект"
    Поля класса:
    //NOTE -  v 1.0
[x]  _name         : (string)                             -название задачи
[x]  _description  : (string)                             -описание задачи (опционально)
[x]  _creation_date: (пользовательский тип data_t)        -дата создания   (инициализация при создании объекта класса)
[x]  _ending_date  : (пользовательский тип data_t)        -дата окончания  (опционально)
[x]  _status       : (bool)                               -готова ли задача

    Методы класса:
    //NOTE -  v 1.0
        Возможны несколько видов конструкторов:
[x]{x}   -c заполнением всех полей(некоторые поля, могут быть не проинициализированными, важно учитывать!)
[x]{x}   получить значение/изменить _name
[x]{x}   получить значение/изменить _description
[x]{x}   добавить/убрать дату окончания
[x]{x}   выставить/убрать признак готовности задачи

    update: (то есть возможно добавление в след версии)
        1) Возможность прикреплять теги к пунктам. Тогда такой тег относится и к пункту, и к задаче, 
        чтобы найти какие пункты соответствуют нужному тегу
        2) Наличие подзадач и работа с ними
        3) Поиск
*******************************************************************************************************************************************/
#pragma once

#include <string>
#include <cstring>


#include "global_lib.h"


class Task
{
private:
    std::string _name,
                _description;
    STATUS _status;

    data_t _creation_date{},
           _ending_date  {};

public:
    Task() = delete;

    Task(const std::string &name, const std::string& description = "", STATUS is_done = STATUS::FAIL,
         const data_t &ending_date = {0, 0, 0, 0, 0});

    /*! @brief  Возвращает название задачи */
    std::string name(void) const noexcept { return _name; }
    std::string name(void)       noexcept { return _name; }

    /*! @brief  Возвращает описание задачи */
    std::string description(void) const noexcept { return _description; }
    std::string description(void)       noexcept { return _description; }

    /*! @brief  Возвращает текущий статус задачи */
    STATUS status( void) const noexcept { return _status; }
    STATUS status( void) noexcept       { return _status; }

    /*! @brief Изменить название задачи */
    STATUS set_name ( const std::string& name_task ) noexcept { _name = name_task;
                                                                return STATUS::SUCCES; };

    /*! @brief Изменить описание задачи */
    STATUS set_description(const std::string& description_task) noexcept { _description = description_task;
                                                                                return STATUS::SUCCES; }
    /*! @brief Возвращает признак готовности задачи
        @param attribute  (см task_lib.h) DONE      - пометить как готовую
                                          NO_READY  -           не готовую
                                          INVARIABLY- не изменять текущее состояние признака */
    STATUS change_status(STATUS attribute) noexcept;

    /*! @brief Добавить дату окончания */
    void add_ending_date(data_t date) noexcept;

    /*! @brief Удалить дату окончания */
    void delete_ending_date( void ) noexcept { memset(&_ending_date, 0, sizeof(data_t)); }

};


inline bool operator<(const Task &lhs, const Task &rhs)
{
    return std::lexicographical_compare(lhs.name().begin(), lhs.name().end(), rhs.name().begin(), rhs.name().end());
}