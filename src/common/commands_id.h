/**
 * @file commands.h
 * @author chumakov <d.tchumackov2013@yandex.ru>
 * @brief Описание команд, которые возможно выполнить в программе
 * @version 0.1
 * @date 2026-04-19
 * 
 * @copyright Copyright (c) 2026
 * 
 */
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