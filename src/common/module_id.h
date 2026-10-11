#pragma once

#include <cstdint>

enum class ModuleId : uint8_t
{
    Invalid = 0,
    Core = 1,
    // Network = 2,
    // Storage = 3,
    UI = 4,
    // MaxModuleId
};