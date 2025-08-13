#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "lib.h"

namespace lib
{

class Service_Class
{
public:
    /*! @brief Кол-во задач в классе обслуживания */
    virtual int count_all_task(void) const noexcept = 0;
    virtual int count_all_task(void) noexcept       = 0;

    /*! @brief Кол-во решенных задач в классе обслуживания  */
    virtual int count_done_task(void) const noexcept = 0;
    virtual int count_done_task(void) noexcept       = 0;

    /*! @brief Наименование класса обслуживания */
    virtual std::string name_level(void) const noexcept = 0;
    virtual std::string name_level(void) noexcept       = 0;

    /*! @brief Добавить новую задачу */
    virtual STATUS add_task(const std::string &name_task)= 0;

    /*! @brief Убрать задачу */
    virtual STATUS remove_task(const std::string &name_task)= 0;
};

}