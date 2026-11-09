/**
 * @file commands.h
 * @author chumakov (<d.tchumackov2013@yandex.ru>)
 * @brief Описание сущности Команда - сообщения от модуля интерфейса
 * @version 0.1
 * @date 2026-04-19
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#pragma once

#include <cstdint>
#include <variant>
#include <string>
#include <iostream>

namespace common
{
    enum class CommandId : uint16_t {
        None,
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
    
    
    struct CreateTaskCommand {
        std::string name;         /* Название задачи */
    };
    
    using CommandPayload = std::variant<
        CreateTaskCommand
    >;
    
    struct Command {
        CommandId command_id;    /* Идентификатор команды */
        CommandPayload payload; 
    };
}

inline std::ostream& operator << ( std::ostream& os, const common::CommandId& cmd )
{
    constexpr auto commandIdToString = []( common::CommandId id ) -> std::string_view {
        switch (id) {
            case common::CommandId::None: return "None";
            case common::CommandId::CreateTask: return "CreateTask";
            case common::CommandId::DeleteTask: return "DeleteTask";
            case common::CommandId::ExitProgram: return "ExitProgram";
            case common::CommandId::NavigateUp: return "NavigateUp";
            case common::CommandId::NavigateDown: return "NavigateDown";
            case common::CommandId::NavigateLeft: return "NavigateLeft";
            case common::CommandId::NavigateRight: return "NavigateRight";
            case common::CommandId::OnSetting: return "OnSetting";
            case common::CommandId::OffSetting: return "OffSetting";
            default: return "Unknown";
        }
    };
    os << "CommandId: " << commandIdToString(cmd);
    return os;
}



