#pragma once

#include <variant>
#include <cstdint>
#include <string>

struct EventStart
{
    std::string name_board;
};

struct EventAddNewTask
{
    std::string name_new_task;
};


using PayloadCore2Ui = std::variant< std::monostate, EventStart, EventAddNewTask >;


struct EventMessage{
    uint64_t id;
    PayloadCore2Ui payload;
};