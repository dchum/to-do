#pragma once

#include <queue>
#include <stdexcept>

#include "commandmessage.h"
#include "commands_id.h"

#include "cui_screen.h"

namespace cui
{

template<CommandId cmd>
struct CommandImpl {};

namespace commands
{

void Execute( CommandId cmd, CUIScreen& screen, std::queue<MessagePayload>& queue_mes );

}//namespace commands

}//namespace cui