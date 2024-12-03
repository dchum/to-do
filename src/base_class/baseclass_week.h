/*****************************************************************************************************************************
[x]          - признак наличия метода/поля в коде
{x}          - признак наличия покрывающего теста для того или иного метода/поля
*опционально - обязательно к реализации, но использование класса возможно и без этого поля
    
    Класс "Неделя" - Week. Используется в интерфейсах "Еженедельное планирование"
    Поля класса:
    //NOTE -  v 1.0
[x] _count_done_task : int                       - кол-во выполненных задач на неделе
[x] _count_all_task  : int                       - кол-во всех задач на неделе
[x] _days_week       : _days_week[NUM_DAY_WEEK]  - вектор дней недели

    Методы класса:
    //NOTE -  v 1.0
[x]{ } выдать число всех/выпо/невыполненных задач

    update:
    1. Добавить теги и поиск по ним
    2. Поиск
****************************************************************************************************************************** */
#pragma once

#include <string>
#include <vector>

#include "baseclass_day.h"

#include "global_lib.h"




class Week
{
private:
    int _count_done_task,
        _count_all_task;

    std::vector<Day> _days_week;

public:
    Week();

    /**Кол-во выполненных задач */
    int count_done_task(void) const noexcept { return _count_done_task; }
    int count_done_task(void) noexcept       { return _count_done_task; }

    /**Кол-во всех задач */
    int count_all_task(void) const noexcept  { return _count_all_task; }
    int count_all_task(void) noexcept        { return _count_all_task; }

    /**Кол-во невыполненных задач */
    int count_notready_task(void) const noexcept { return _count_all_task - _count_done_task; }
    int count_notready_task(void) noexcept       { return _count_all_task - _count_done_task; } 

    /**Обновляем текущую статистику */
    void update(void);
};