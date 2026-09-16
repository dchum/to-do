#pragma once

#include <vector>
#include <string>
#include <iostream>

#define STR(x) #x


/*! @brief Признак успешности работы ф-и,
   Использовать везде, где требуется дать односложный ответ "да/нет"
   VOID - аналогичен void */
enum class CODE_RESULT
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
