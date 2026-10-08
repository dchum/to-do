/**
 * @file header_message.h
 * @author chumakov (<d.tchumackov2013@yandex.ru>)
 * @brief Заголовок любой посылки между модулями
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

struct HeaderMessage {
    uint64_t       id;    /* Уникальный идентификатор каждого снимка*/
    uint32_t  version;    /* Версия снимка, принимающая сторона обязана поддерживать эту версию или выше */
};

struct CreateTaskCommand {
    std::string name;         /* Название задачи */
};

using CommandPayload = std::variant<
    CreateTaskCommand,
>;

struct Command {
    CommandId command_id;   /* Идентификатор команды */
    HeaderMessage header;   /* Заголовок команды */
    CommandPayload payload; 
};



