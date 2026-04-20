#include "ui.h"

void ui::Ui::HandleInput()
{
    auto cmdmessage = cui_core_.handleInput();

    if ( cmdmessage != std::nullopt )
        queue_ui2core_.push( cmdmessage.value() );
}