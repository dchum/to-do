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
[x]  _tags         : (set<string>)                        -набор тегов
[x]  _sub_items    : (list<pair<std::string, STATUS>>)    -подзадачи, пункты. Тут будут названия пунктов и признак их готовности
                                                            ключом будет номер пункта, значением - описание и признак готовности

[x]  _progress     : (float)                              -прогресс по задачи. (опционально)
                                                            Зависит от числа выполненных подзадач,
                                                            подпунктов. Нужно быть внимательным, поскольку подзадач может и не быть вовсе.
                                                            В таком случае прогресс никак не регистрируется.
                                                            Значение от 0 до 1.
[x]  _count_items  : (int)                                -количество подзадач. Размер словаря _sub_items

    Методы класса:
    //NOTE -  v 1.0
        Возможны несколько видов конструкторов:
[x]{ }   дефолтный
[x]{ }   c заполнением всех полей(некоторые поля, могут быть не проинициализированными, важно учитывать!)
[x]{ }   получить значение/изменить _name
[x]{ }   получить значение/изменить _description
[x]{ }   добавить/убрать дату окончания
[x]{ }   выставить/убрать признак готовности задачи
[x]{ }   добавить/убрать тег/и к задаче
[x]{ }   добавить/убрать пункты задачи
[x]{ }   выставить/снять признак готовности пункта
[x]{ }   найти тег. Ответ на вопрос, имеет ли текущая задача конкретный тег или нет
[x]{ }   получить все множество тегов
[x]{ }   получить/обновить _progress по задаче
[x]{ }   получить кол-во пунктов

    update: (то есть возможно добавление в след версии)
        1) Возможность прикреплять теги к пунктам. Тогда такой тег относится и к пункту, и к задаче, чтобы найти какие пункты соответствуют нужному тегу
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
    float _progress = 0.;
    int _count_items = 0;

    data_t _creation_date{},
        _ending_date{};

    std::set<std::string> _tags;

    std::list<SUB_ITEMS> _sub_items;

public:
    Task() = default;

    Task(const std::string &name, const std::string &description = ""s, STATUS is_done = STATUS::FAILURE, float progress = 0.,
         const data_t &ending_date = {0, 0, 0, 0, 0},
         const std::set<std::string> &tags = {});

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
    
    /*! @brief Изменить статус подзадачи*/
    STATUS change_items_status(const string &description, STATUS attribute);

    /*! @brief Возвращает кол-во пунктов */
    int size_sub_items(void);

    /*! @brief Добавить тег */
    STATUS add_tag(const std::string &tag);

    /*! @brief Удалить тег */
    STATUS remove_tag(const std::string &tag);

    /*! @brief Имеет ли задача данный тег или нет */
    STATUS have_tag(const std::string &tag);

    /*! @brief Получить все теги */
    std::set<std::string> get_tags(void) const;

    /*! @brief Добавить пункт в задачу*/
    void add_items(string &items);

    /*! @brief Удалить пункт из задачи по описанию пункта*/
    STATUS delete_items(const string &description);

    /*! @brief Добавить дату окончания */
    void add_ending_date(data_t date);

    /*! @brief Удалить дату окончания */
    void delete_ending_date(void);

private:
    /*! @brief Обновление значения прогресса по задаче исходя из выполненных пунктов */
    void update_progress(void);
};


inline bool operator<(const Task &lhs, const Task &rhs)
{
    return std::lexicographical_compare(lhs.name().begin(), lhs.name().end(), rhs.name().begin(), rhs.name().end());
}