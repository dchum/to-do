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
enum WEEKDAY
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

/*Классы обслуживания для канбан-доски*/
enum class SERVISE_CLASS
{
    BACKLOG,        /*Запланировано*/
    IN_PROGRESS,    /*В процессе*/
    DONE            /*Готово*/
};