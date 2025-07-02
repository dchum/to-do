#pragma once

namespace lib
{

class Task
{
public:
    /*! @brief  Возвращает название задачи */
    virtual std::string name(void) const noexcept = 0;
    virtual std::string name(void)       noexcept = 0;

    /*! @brief  Возвращает описание задачи */
    virtual std::string description(void) const noexcept = 0;
    virtual std::string description(void)       noexcept = 0;

    /*! @brief  Возвращает текущий статус задачи */
    virtual STATUS status( void) const noexcept = 0;
    virtual STATUS status( void) noexcept       = 0;

    /*! @brief Изменить название задачи */
    virtual STATUS set_name ( const std::string& name_task ) noexcept = 0;

    /*! @brief Изменить описание задачи */
    virtual STATUS set_description(const std::string& description_task) noexcept = 0;
    
    /*! @brief Возвращает признак готовности задачи
        @param attribute  (см task_lib.h) DONE      - пометить как готовую
                                          NO_READY  -           не готовую
                                          INVARIABLY- не изменять текущее состояние признака */
    virtual STATUS set_status(STATUS attribute) noexcept = 0;

    virtual void add_ending_date(data_t date) noexcept = 0;

    virtual void delete_ending_date( void ) noexcept = 0;
};

}