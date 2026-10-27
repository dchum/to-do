#pragma once

#include "commands.h"
#include "events.h"
#include "header_message.h"

namespace common
{
    struct Message
    {
        HeaderMessage header;
        std::variant<Command,Event> payload;
    };
}