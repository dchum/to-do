/*****************************************************************************************************************************
    Класс "День" - Day. Используется в интерфейсах "Еженедельное планирование"
    Поля класса:
    //NOTE -  v 1.0
[x]  _set_task          : set<int, Task>            - список всех задач Task для этого дня
[x]  _date              : date_t                    - день, месяц
[x]  _count_done_task   : int                       - кол-во выполненных задач в дне

    Методы класса:
    //NOTE -  v 1.0
[x]{ } констуктор по умолчанию
[x]{ } получить нужную задачу
[x]{ } удалить/добавить задачу
[x]{ } получить кол-во выполненных задач
[x]{ } получить дату для дня (день, месяц)
[ ]{ } найти задачу /*TODO реализовать поиск

//TODO - возможно появится необходимость реализовать доступ по итераторам для for range цикла
****************************************************************************************************************************** */

#pragma once

#include <set>
#include <utility>
#include <string>

#include "task.h"
#include "global_lib.h"

using namespace std;

class Day
{
private:
    int _count_done_task = 0;
    data_t _date = {.hours = -1, .minutes = -1, .day = 0, .month = 0, .year = 0};

    set<Task> _set_task;

public:
    Day();

    pair<int, int> date(void);

    int count_done_task(void);

    int count_all_task(void) const;

    STATUS add_new_task(Task task);

    STATUS delete_task(const string &name_task);

    const Task &get_task(const string &name_task) const;
};