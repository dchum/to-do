/**
 * @file commandmessage.h
 * @author chumakov (<d.tchumackov2013@yandex.ru)
 * @brief Описание посылки UI->Core
 * @version 0.1
 * @date 2026-04-19
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include <variant>

#include "commands_id.h"
#include "header_message.h"

#include "payload_create_task.h"

using MessagePayload = std::variant<typename MessageUI<CommandId::CreateTask>::type >;

struct CommandMessage {
    HeaderMessage  header;
    CommandId      command;
    MessagePayload message;

    static CommandMessage Create( HeaderMessage header, CommandId command, MessagePayload message ) {
        return CommandMessage{.header = header, .command = command, .message = message};
    }
};