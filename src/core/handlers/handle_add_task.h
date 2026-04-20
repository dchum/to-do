#pragma once

#include "handler.h"

#include "model_service.h"

namespace core
{
    class AddNewTask {
    
    public:
        void Execute( Board& board, MessageAddNewTask& message );
    };
    
    template <>
    struct HandlerImpl<CommandId::CreateTask> {
        using type = AddNewTask;
    };

}//namespace core
