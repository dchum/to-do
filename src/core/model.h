#pragma once

#include <vector>
#include <optional>

#include "model_service.h"

#include "message_ui2core.h"
#include "message_core2ui.h"

namespace core
{

class Model
{
    Board board_;
    std::vector<EventMessage> events_;

    class ModelExecutor
    {
    public:
        static std::optional<EventMessage> handle( const CmdStart& cmd, Board& board );
        static std::optional<EventMessage> handle( const CmdAddNewTask& cmd, Board& board );
        static std::optional<EventMessage> handle( const std::monostate&, Board& ) { return std::nullopt; }
    };

public:
    void update ( CommandMessage cmd ) {
        std::visit([this](auto&& arg) {
                //FIXME - добавить проверку на наличие необходимой перегрузки
                if (auto event = ModelExecutor::handle(arg, board_)) {
                    events_.push_back(*event);//FIXME - ???*
                }
        }, cmd.payload);
    };

    EventMessage process( void );
};//class Model

}//namespace core