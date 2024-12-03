/*****************************************************************************************************************************
[x]          - признак наличия метода/поля в коде
{x}          - признак наличия покрывающего теста для того или иного метода/поля
*опционально - обязательно к реализации, но использование класса возможно и без этого поля

    Класс "День" - Day. Используется в интерфейсах "Еженедельное планирование"
    Поля класса:
    //NOTE -  v 1.0
[x]  _tasks_day         : set<int, Task>            - список всех задач Task для этого дня
[x]  _date              : date_t                    - день, месяц
[x]  _count_done_task   : int                       - кол-во выполненных задач в дне

    Методы класса:
    //NOTE -  v 1.0
[x]{ } констуктор по умолчанию
[x]{ } получить нужную задачу
[x]{ } удалить/добавить задачу
[x]{ } получить кол-во выполненных задач
[x]{ } получить дату для дня (день, месяц)

//TODO - возможно появится необходимость реализовать доступ по итераторам для for range цикла
update: (то есть возможно добавление в след версии)
        1) расширенная информация о дате
        2) работа с тегами
        3) Поиск
****************************************************************************************************************************** */

#pragma once

#include <set>
#include <utility>
#include <string>

#include "baseclass_task.h"
#include "global_lib.h"

class Day
{
private:
    int _count_done_task = 0;
    data_t _date;

    std::set<Task> _tasks_day;

public:
    Day();

    data_t date(void) const noexcept { return _date; }
    data_t date(void) noexcept       { return _date; }

    int count_done_task(void);

    int count_all_task(void) const;

    STATUS add_new_task(Task task);

    STATUS delete_task(const std::string &name_task);

    const Task &get_task(const std::string &name_task) const;
};