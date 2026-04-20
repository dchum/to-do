#include "cui_command.h"

#include "add_new_task.h"

void cui::commands::Execute( CommandId cmd, CUIScreen& screen, std::queue<MessagePayload>& queue_mes ) {
    switch ( cmd )
    {
        case CommandId::CreateTask:
            cui::CommandImpl<CommandId::CreateTask>::type{}.Execute( screen, queue_mes );
            break;
        
        default:
            throw std::runtime_error( "No matching specialization CommandImpl<>!" );
            break;
    }
}