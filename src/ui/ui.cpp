#include "ui.h"

CommandMessage ui::Ui::HandleInput()
{
    return cui_core_.handleInput();
}

void ui::Ui::update(EventMessage event)
{
    cui_core_.update( event );
}
