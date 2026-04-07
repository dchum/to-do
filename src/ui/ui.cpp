#include "ui.h"

CommandMessage ui::Ui::HandleInput()
{
    return cui_core_.handleInput();
}