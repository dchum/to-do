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
[x]  _is_done      : (bool)                               -готова ли задача

    Методы класса:
    //NOTE -  v 1.0
        Возможны несколько видов конструкторов:
[x]{ }   дефолтный
[x]{ }   c заполнением всех полей(некоторые поля, могут быть не проинициализированными, важно учитывать!)
[x]{ }   получить значение/изменить _name
[x]{ }   получить значение/изменить _description
[x]{ }   добавить/убрать дату окончания
[x]{ }   выставить/убрать признак готовности задачи

    update: (то есть возможно добавление в след версии)
        1) Возможность прикреплять теги к пунктам. Тогда такой тег относится и к пункту, и к задаче, 
        чтобы найти какие пункты соответствуют нужному тегу
        2) Наличие подзадач и работа с ними
*******************************************************************************************************************************************/
#pragma once

#include <string>
#include <list>
#include <set>
#include <utility> /* для pair */

#include "global_lib.h"

using namespace std;


typedef std::pair<string, STATUS> SUB_ITEMS;
class Task
{
private:
    std::string _name = ""s,
                _description = ""s;
    STATUS _is_done = STATUS::FAILURE;
    int _count_items = 0;

    data_t _creation_date{},
           _ending_date  {};

public:
    Task() = default;

    Task(const std::string &name, const std::string &description = ""s, STATUS is_done = STATUS::FAILURE,
         const data_t &ending_date = {0, 0, 0, 0, 0});

    /*! @brief  Возвращает название задачи */
    std::string name(void) const;

    /*! @brief  Возвращает описание задачи */
    std::string description(void) const;

    /*! @brief  Возвращает прогресс по задачи */
    float progress(void);

    /*! @brief Изменить название задачи */
    STATUS set_name_task(const string& name_task);

    /*! @brief Изменить описание задачи */
    STATUS set_description_task(const string& description_task);

    /*!
        @brief Возвращает признак готовности задачи
        @param attribute  (см task_lib.h) DONE      - пометить как готовую
                                          NO_READY  -           не готовую
                                          INVARIABLY- не изменять текущее состояние признака
    */
    STATUS change_task_status(STATUS attribute);

    /*! @brief Добавить дату окончания */
    void add_ending_date(data_t date);

    /*! @brief Удалить дату окончания */
    void delete_ending_date(void);

};


inline bool operator<(const Task &lhs, const Task &rhs)
{
    return std::lexicographical_compare(lhs.name().begin(), lhs.name().end(), rhs.name().begin(), rhs.name().end());
}