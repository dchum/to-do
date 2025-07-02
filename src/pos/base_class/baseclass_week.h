// /*****************************************************************************************************************************
// [x]          - признак наличия метода/поля в коде
// {x}          - признак наличия покрывающего теста для того или иного метода/поля
// *опционально - обязательно к реализации, но использование класса возможно и без этого поля
    
//     Класс "Неделя" - Week. Используется в интерфейсах "Еженедельное планирование"
//     Поля класса:
//     //NOTE -  v 1.0
// [x] _days_week       : _days_week[NUM_DAY_WEEK]  - вектор дней недели

//     Методы класса:
//     //NOTE -  v 1.0
// [x]{ } выдать число всех/выпо задач

//     update:
//     1. Добавить теги и поиск по ним
//     2. Поиск
// ****************************************************************************************************************************** */
// #pragma once

// #include <string>
// #include <vector>

// #include "baseclass_day.h"

// #include "global_lib.h"


// namespace pos
// {
    
// class Week
// {
// private:
//     std::vector<Day> _days_week;

// public:
//     Week();

//     /*! @brief Кол-во выполненных задач */
//     int count_done_task(void) const noexcept { return std::accumulate(_days_week.begin(), _days_week.end(), 0, 
//                                                                         [](int curr_sum, const Day &day)
//                                                                         { return  curr_sum + day.count_done_task();} ); }
//     int count_done_task(void) noexcept       { return std::accumulate(_days_week.begin(), _days_week.end(), 0, 
//                                                                         [](int curr_sum, const Day &day)
//                                                                         { return  curr_sum + day.count_done_task();} ); }

//     /*! @brief Кол-во всех задач */
//     int count_all_task(void) const noexcept  { return  std::accumulate(_days_week.begin(), _days_week.end(), 0, 
//                                                                         [](int curr_sum, const Day &day)
//                                                                         { return  curr_sum + day.count_all_task();} ); }
//     int count_all_task(void) noexcept        { return  std::accumulate(_days_week.begin(), _days_week.end(), 0, 
//                                                                         [](int curr_sum, const Day &day)
//                                                                         { return  curr_sum + day.count_all_task();} ); }

//     // auto get_day(WEEKDAY day, )

//     auto cbegin()  const { return _days_week.cbegin(); }
//     auto begin()         { return _days_week.begin(); }

//     auto cend() const { return _days_week.cend(); }
//     auto end()        { return _days_week.end();  }

// private:
//     // /*! @brief Обновляем текущую статистику */
//     // void update(void); //NOTE - до лучших времен
// };

// }
