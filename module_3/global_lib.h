#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

/* Признак успешности работы ф-и, выполненности пункта/задачи и т.д.
   Использовать везде, где требуется дать односложный ответ "да/нет"
   INVARIABLY - аналогичен void, исползовать когда не требуется изменятьтекущее состояние*/
enum class STATUS
{
    SUCCES,
    FAILURE,
    INVARIABLY
};

/*Признак ф-й для чтения и записи свойств*/
enum class STATUS_PROPERTY
{
    READ,
    WRITE
};

/*Структура для представления времени в проекте*/
typedef struct
{
    int hours,
        minutes,
        day,
        month,
        year;
} data_t;

/*Дни недели*/
enum class WEEKDAY
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    NUM_DAY_WEEK
};

/*Классы обслуживания для канбан-доски, по-умолчанию*/
enum SERVISE_CLASS
{
    BACKLOG,     /*Запланировано*/
    IN_PROGRESS, /*В процессе*/
    DONE         /*Готово*/
};

std::ostream &operator<<(std::ostream &os, const vector<string>& vector_to_string);
