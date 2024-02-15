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

    update: (то есть возможно добавление в след версии)
        1) Возможность прикреплять теги к пунктам. Тогда такой тег относится и к пункту, и к задаче, чтобы найти какие пункты соответствуют нужному тегу

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
[x]{ }   получить/обновить _progress по задаче
[x]{ }   получить кол-во пунктов

*******************************************************************************************************************************************/
#pragma once

#include <string>
#include <list>
#include <set>
#include <utility> /* для pair */
#include <chrono>  /* для учета времени */
#include <ctime>
#include <stdexcept>

#include "task_lib.h"

using namespace std;

typedef struct
{
    int  hours,
         minutes,
         day,
         month, 
         year;
}data_t;

typedef pair<string, STATUS> SUB_ITEMS;

class Task
{
    public:
        Task() = default;

        //TODO - в конструкторе заполнять дату создания
        Task(const std::string& name, const std::string& description = ""s, STATUS is_done = STATUS::FAILURE, float progress = 0., 
        const data_t& ending_date   = {0, 0, 0, 0, 0}, 
        const std::set<std::string>& tags = {}) 
        : _name(name), 
          _description(description), 
          _is_done(is_done), 
          _progress(progress),
          _ending_date(ending_date), 
          _tags(tags) 
        {
            _count_items = 0;

            auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::tm* timeInfo = std::localtime(&currentTime);
            
            _creation_date = {
                .hours   = timeInfo->tm_hour, 
                .minutes = timeInfo->tm_min, 
                .day     = timeInfo->tm_mday,
                .month   = timeInfo->tm_mon + 1, // tm_mon начинается с 0
                .year    = 1900 + timeInfo->tm_year,
            };
        }

        /*! @brief  Возвращает название задачи */
        std::string& get_name(void)
        {
            return _name;
        }

        /*! @brief  Возвращает описание задачи */
        std::string& get_description(void)
        {
            return _description;
        }

        /*! @brief  Возвращает прогресс по задачи */
        float get_progress( void )
        {
            return _progress;
        }

        /*! @brief Обновление значения прогресса по задаче исходя из выполненных пунктов */
        void update_progress( void )
        {
            int number_completed_items = 0;
            for (const auto& [name, is_done] : _sub_items)
            {
                if (is_done == STATUS::SUCCES) number_completed_items++;
            }
            _progress = (number_completed_items * 1.) / (_sub_items.size() * 1.);
        }

        /*! 
            @brief Возвращает признак готовности задачи 
            @param attribute  (см task_lib.h) DONE      - пометить как готовую 
                                              NO_READY  -           не готовую
                                              INVARIABLY- не изменять текущее состояние признака
        */
        STATUS change_task_status( ATTRIBUTE_TASK attribute )
        {
            switch (attribute)
            {
                case ATTRIBUTE_TASK::DONE:
                    _is_done = STATUS::SUCCES;
                    break;
                case ATTRIBUTE_TASK::NO_READY:
                    _is_done = STATUS::FAILURE;
                    break;
                case ATTRIBUTE_TASK::INVARIABLY:
                default:
                    break;
            }
            return _is_done;
        }

        STATUS change_items_status( const string& description,  ATTRIBUTE_TASK attribute )
        {
            auto iter = _sub_items.begin();
            while (iter != _sub_items.end()) 
            {
                if ( iter->first == description )   break;
            }
            
            if ( iter == _sub_items.end() ) throw logic_error("ERROR: The item is missing/n");

            switch (attribute)
            {
                case ATTRIBUTE_TASK::DONE:
                    iter->second = STATUS::SUCCES;
                    break;
                case ATTRIBUTE_TASK::NO_READY:
                    iter->second = STATUS::FAILURE;
                    break;
                case ATTRIBUTE_TASK::INVARIABLY:
                default:
                    break;
            }
            return iter->second;
        }

        /*! @brief Возвращает кол-во пунктов */
        int get_size_sub_items( void )
        {
            return _sub_items.size();
        }

        /*! @brief Добавить тег */
        STATUS add_tag( const std::string& tag )
        {
            auto ret = _tags.insert(tag);

            return ret.second? STATUS::SUCCES : STATUS::FAILURE;
        }

        /*! @brief Удалить тег */
        STATUS remove_tag( const std::string& tag )
        {
            auto ret = _tags.erase(tag);

            return ret == 1 ? STATUS::SUCCES : STATUS::FAILURE;
        }

        /*! @brief Имеет ли задача данный тег или нет */
        STATUS have_tag( const std::string& tag )
        {
            return _tags.count( tag ) ? STATUS::SUCCES : STATUS::FAILURE;
        }

        /*Добавить пункт в задачу*/
        void add_items(  string& items )
        {
            _sub_items.push_back(make_pair(items, STATUS::FAILURE));
        }
        /*Удалить пункт из задачи по описанию пункта*/
        STATUS delete_items( const string& description )
        {
            auto iter = _sub_items.begin();
            while (iter != _sub_items.end()) 
            {
                if ( iter->first == description )   break;
            }

            auto ret = _sub_items.erase(iter);

            return iter != _sub_items.end() ? STATUS::SUCCES : STATUS::FAILURE;
        }

        void add_ending_date( data_t date )
        {
            _ending_date.day     = date.day;
            _ending_date.hours   = date.hours;
            _ending_date.minutes = date.minutes;
            _ending_date.month   = date.month;
            _ending_date.year    = date.year;
        }

        void delete_ending_date( void )
        {
            _ending_date = {.hours = 0, .minutes = 0, .day = 0, .month = 0, .year = 0};
        }


    private:
        std::string _name        = ""s, 
                    _description = ""s;
        STATUS      _is_done     = STATUS::FAILURE;
        float       _progress    = 0.;
        int         _count_items = 0;

        data_t  _creation_date{},
                _ending_date  {};
        
        std::set<std::string> _tags;

        std::list<SUB_ITEMS> _sub_items;
};