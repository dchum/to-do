#pragma once

/* Признаки готовности задачи, пункта или чего-то еще. 
   INVARIABLY - использовать когда нужно узнать текущее состояние объкта */
enum class ATTRIBUTE_TASK
{
    DONE        = 0,
    NO_READY,
    INVARIABLY
}; 

/* Признак успешности работы ф-и, выполненности пункта/задачи и т.д.
   Использовать везде, где требуется дать односложный ответ "да/нет" */
enum class STATUS
{
    SUCCES,
    FAILURE
};

typedef struct
{
    int  hours,
         minutes,
         day,
         month, 
         year;
}data_t;