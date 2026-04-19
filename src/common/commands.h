#pragma once

#include <cstdint>

enum class CommandId : uint16_t {
    CreateTask,
    DeleteTask,
    ExitProgram,
    NavigateUp,
    NavigateDown,
    NavigateLeft,
    NavigateRight,
    OnSetting,
    OffSetting,
};