#pragma once

#include "commands_id.h"

template <CommandId ID>
struct MessageUI{
    static_assert(false, 
        "=================================================================\n"
        "   No specialization of MessageUI<> for this type!\n\n"
        "=================================================================");
};