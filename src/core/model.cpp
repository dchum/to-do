#include "model.h"

#include "handler.h"

void core::Model::update(CommandMessage cmd)
{
    core::commands::Execute( cmd.command, board_, cmd.message );
}
