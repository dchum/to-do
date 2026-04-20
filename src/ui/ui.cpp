#include "ui.h"

void ui::Ui::init(std::queue<CommandMessage> &queue_ui2core)
{
    queue_ui2core_ = &queue_ui2core;
}

void ui::Ui::HandleInput()
{
    auto cmdmessage = cui_core_.handleInput();

    if ( cmdmessage != std::nullopt )
        queue_ui2core_->push( cmdmessage.value() );
}