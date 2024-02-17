#pragma once

/* Признак успешности работы ф-и, выполненности пункта/задачи и т.д.
   Использовать везде, где требуется дать односложный ответ "да/нет" 
   INVARIABLY - аналогичен void, исползовать когда не требуется изменятьтекущее состояние*/
enum class STATUS
{
    SUCCES,
    FAILURE,
    INVARIABLY
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
enum class Week
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};