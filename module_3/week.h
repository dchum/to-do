/*****************************************************************************************************************************
    Класс "Неделя" - Week. Используется в интерфейсах "Еженедельное планирование"
    Поля класса:
    //NOTE -  v 1.0
[x] _count_done_task : int                      - кол-во выполненных задач на неделе
[x] _count_all_task  : int                      - кол-во всех задач на неделе
[x] _days_week       : _days_week[NUM_DAY_WEEK]  - вектор дней недели

    Методы класса:
    //NOTE -  v 1.0
[x]{ } поиск по тегу   - на выходе выдать дни и задачи в этом дне
[ ]{ } найти задачу /*TODO реализовать поиск
[x]{ } выдать число всех/выпо/невыполненных задач

    update:
    1. Сейчас поиск идет по 100% совпадению. Реализовать позже выдачу результатов и по частичному совпадению: совпали некоторые
    слова
    2. Реализовать параллельный поиск
****************************************************************************************************************************** */
#pragma once

#include <string>
#include <vector>
#include <utility>

#include "day.h"
#include "global_lib.h"

using namespace std;

class Week
{
private:
    int _count_done_task = 0,
        _count_all_task = 0;

    vector<Day> _days_week;

public:
    Week();

    /**Кол-во выполненных задач */
    int count_done_task(void) noexcept;

    /**Кол-во всех задач */
    int count_all_task(void) noexcept;

    /**Кол-во невыполненных задач */
    int count_notready_task(void) noexcept;

    /**Поиск задачи в недели */
    std::vector<std::pair<Day, Task>> task_search(const string &name_task);

    /**Поиск задачи по тегу среди недели */
    std::vector<std::pair<Day, Task>> tag_search(const string &name_tag);

private:
    /**Обновляем текущую статистику */
    void update(void);
};