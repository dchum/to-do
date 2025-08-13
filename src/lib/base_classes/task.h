#pragma once

#include <string_view>
#include <string>

#include "lib.h"

namespace lib
{

    class Task
    {
    private:
        std::string _name,
                    _description;
        STATUS _status;
        data_t _creation_date{},
               _ending_date  {};

    void swap(Task& other);
            
    public:
        Task( const std::string& name, 
              const std::string& description = "", 
              STATUS is_done = STATUS::FAIL,
              const data_t &ending_date = {0, 0, 0, 0, 0}
            );

        Task() = delete;
        Task (const Task& );
        Task (const Task&& ) = delete;

        Task& operator=( const Task& other );
        Task& operator=( const Task&& other ) = delete;

    public:
        /*! @brief  Возвращает название задачи */
        virtual std::string name(void)        const noexcept = 0;
        /*! @brief  Возвращает описание задачи */
        virtual std::string description(void) const noexcept = 0;
        /*! @brief  Возвращает текущий статус задачи */
        virtual STATUS status( void)          const noexcept = 0;
        /*! @brief  Возвращает дедлайн по задаче */
        virtual data_t ending_date(const data_t &date) noexcept = 0;

        /*! @brief Изменить название задачи */
        virtual STATUS set_name ( const std::string& name_task ) noexcept = 0;
        /*! @brief Изменить описание задачи */
        virtual STATUS set_description(const std::string& description_task) noexcept = 0;
        /*! @brief Возвращает признак готовности задачи
            @param attribute  (см task_lib.h) DONE      - пометить как готовую
                                              NO_READY  -              не готовую
        virtual STATUS set_status(STATUS attribute) noexcept = 0;
        /*! @brief  изменить дедлайн */
        virtual void set_ending_date( void )   noexcept = 0;
    };

}