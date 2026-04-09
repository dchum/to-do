#pragma once

#include "model_service.h"

#include "message_ui2core.h"

namespace core
{

class Model
{
    Board board_;

    class ModelExecutor
    {
        Board& board_;
    public:
        ModelExecutor( Board& board )  : board_( board ) {}
        
        void operator() ( const std::monostate     ) {  }
        void operator() ( const CmdStart& cmd      );
        void operator() ( const CmdAddNewTask& cmd );
    };
    ModelExecutor executor_;

public:
    Model();

    void init( void ) {}

public:
    void update ( CommandMessage cmd );
};//class Model

}//namespace core