#pragma once

#include <vector>
#include <string>
#include <iostream>

#define STR(x) #x


/* Признак успешности работы ф-и, выполненности пункта/задачи и т.д.
   Использовать везде, где требуется дать односложный ответ "да/нет"
   VOID - аналогичен void, исползовать когда не требуется изменять текущее состояние*/
enum class STATUS
{
    SUCCES,
    FAIL,
    VOID
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
