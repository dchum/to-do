#include "handler.h"

#include <stdexcept>

#include "handle_add_task.h"

void core::commands::Execute(CommandId cmd, Board &board, MessagePayload message)
{
    switch ( cmd )
    {
        case CommandId::CreateTask:
            core::HandlerImpl<CommandId::CreateTask>::type{}.Execute( board, std::get<MessageAddNewTask>(message) );
            break;
        
        default:
            throw std::runtime_error( "No matching specialization HandlerImpl<>!" );
            break;
    }
}