// /*****************************************************************************************************************************
// [x]          - признак наличия метода/поля в коде
// {x}          - признак наличия покрывающего теста для того или иного метода/поля
// *опционально - обязательно к реализации, но использование класса возможно и без этого поля

//     Класс "День" - Day. Используется в интерфейсах "Еженедельное планирование"
//     Поля класса:
//     //NOTE -  v 1.0
// [x]  _tasks_day         : set<int, Task>            - список всех задач Task для этого дня
// [x]  _date              : date_t                    - день, месяц

//     Методы класса:
//     //NOTE -  v 1.0
// [x]{x} констуктор по умолчанию
// [x]{x} получить нужную задачу
// [x]{x} удалить/добавить задачу
// [x]{x} получить кол-во выполненных задач
// [x]{x} получить дату для дня (день, месяц)

// //TODO - возможно появится необходимость реализовать доступ по итераторам для for range цикла
// update: (то есть возможно добавление в след версии)
//         1) расширенная информация о дате
//         2) работа с тегами
//         3) Поиск
// ****************************************************************************************************************************** */

// #pragma once

// #include <list>
// #include <algorithm>
// #include <utility>
// #include <string>

// #include "baseclass_task.h"
// #include "lib.h"




// using const_it_Task = std::list<Task>::const_iterator;
// using it_Task = std::list<Task>::iterator;

// class Day
// {
// private:
//     data_t _date;

//     std::list<Task> _tasks_day;

// public:
//     Day();
    
//     /*! @brief Получить дату */
//     data_t date(void) const noexcept { return _date; }
//     data_t date(void) noexcept       { return _date; }

//     /*! @brief Кол-во всех задач в текущем дне*/
//     int count_all_task(void) const noexcept { return _tasks_day.size(); }
//     int count_all_task(void) noexcept       { return _tasks_day.size(); }

//     /*! @brief Кол-во решенных задач в дне */
//     int count_done_task(void) const noexcept { return std::count_if(_tasks_day.begin(), _tasks_day.end(), 
//                                                                     [] ( const Task& tmp ) { return tmp.status() == STATUS::SUCCES; }); }
//     int count_done_task(void) noexcept       { return std::count_if(_tasks_day.begin(), _tasks_day.end(), 
//                                                                     [] ( const Task& tmp ) { return tmp.status() == STATUS::SUCCES; }); }

//     /*! @brief Добавить новую задачу */
//     STATUS add_new_task(Task task) { _tasks_day.push_back(task); return STATUS::SUCCES; }

//     /*! @brief Удалить задачу */
//     STATUS delete_task(const std::string &name_task);

//     /*! @brief Получить итератор на задачу */
//     it_Task       get_task(const std::string &name_task);
//     const_it_Task get_const_task(const std::string &name_task) const;

//     auto begin()  { return _tasks_day.begin();  };
//     auto cbegin() { return _tasks_day.cbegin(); };

//     auto end()  { return _tasks_day.end();  };
//     auto cend() { return _tasks_day.cend(); };

//     // void update(); //NOTE - на случай если потребуется обновление состояния
// };