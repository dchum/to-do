#pragma once

#include <variant>
#include <cstdint>
#include <string>

struct CmdStart
{
    std::string name_board;
};

struct CmdAddNewTask
{
    std::string name_new_task;
};


using PayloadeUi2Core = std::variant< std::monostate, CmdStart, CmdAddNewTask >;


struct CommandMessage{
    uint64_t id;
    PayloadeUi2Core payload;
};