#pragma once

#include "commands.h"
#include "events.h"
#include "header_message.h"

struct Message
{
    HeaderMessage header;
    std::variant<Command,Event> payload;
};