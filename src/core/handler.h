#pragma once

#include "commands_id.h"
#include "commandmessage.h"

#include "model_service.h"

namespace core{

template<CommandId cmd>
struct HandlerImpl {};

namespace commands
{

void Execute( CommandId cmd,  Board& board, MessagePayload message );

}

}//namespace core