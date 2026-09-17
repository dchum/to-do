/******************************************************************************************************************************************
[x]          - признак наличия метода/поля в коде
{x}          - признак наличия покрывающего теста для того или иного метода/поля
*опционально - обязательно к реализации, но использование класса возможно и без этого поля

    Класс "Задача" - Task. Используется в интерфейсах "Еженедельное планирование" и "Проект"
    Поля класса:
    //NOTE -  v 1.0
[x]  name_         : (string)                             -название задачи
[x]  description_  : (string)                             -описание задачи (опционально)
[x]  creation_date_: (пользовательский тип data_t)        -дата создания   (инициализация при создании объекта класса)
[x]  ending_date_  : (пользовательский тип data_t)        -дата окончания  (опционально)
[x]  status_task_       : (bool)                               -готова ли задача

    Методы класса:
    //NOTE -  v 1.0
        Возможны несколько видов конструкторов:
[x]{x}   -c заполнением всех полей(некоторые поля, могут быть не проинициализированными, важно учитывать!)
[x]{x}   получить значение/изменить name_
[x]{x}   получить значение/изменить description_
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
#include <stdint.h>

#include "common.h"
#include "lib.h"

namespace core
{

using TaskID = std::uint64_t;

class Task
{
    static TaskID id;

private:
    TaskID id_;
    std::string name_,
                description_;
    STATUS_TASK status_task_;
    PRIORITY_TASK priotity_;

    data_t creation_date_{},
           ending_date_  {};

public:
    Task() = delete;

    Task( const std::string& name, STATUS_TASK is_done = STATUS_TASK::PROCESS );

/*******************Геттеры********************************** */
    /*! @brief  Возвращает название задачи */
    std::string name(void) const noexcept  { return name_; }

    /*! @brief  Возвращает описание задачи */
    std::string description(void) const noexcept  { return description_; }

    /*! @brief  Возвращает текущий статус задачи */
    STATUS_TASK status_task( void) const noexcept  { return status_task_; }
/************************************************************ */

/*******************Сеттеры********************************** */
    /*! @brief Изменить название задачи */
    STATUS_TASK set_name ( const std::string& name_task ) 
    { 
        name_ = name_task; 
        return STATUS_TASK::SUCCES; 
    };

    /*! @brief Изменить описание задачи */
    STATUS_TASK set_description(const std::string& description_task) 
    { 
        description_ = description_task; 
        return STATUS_TASK::SUCCES; 
    }
    
    STATUS_TASK set_status_task(STATUS_TASK attribute) noexcept ;
/************************************************************ */

    /*! @brief Добавить дату окончания */
    void add_ending_date(data_t date) noexcept ;

    /*! @brief Удалить дату окончания */
    void delete_ending_date( void ) noexcept 
    { 
        ending_date_ = {0};
    }
};


}


inline bool operator<(const core::Task &lhs, const core::Task &rhs)
{
    return std::lexicographical_compare(lhs.name().begin(), lhs.name().end(), rhs.name().begin(), rhs.name().end());
}