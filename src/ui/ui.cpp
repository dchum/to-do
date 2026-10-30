#include "ui.h"

#include "common/events.h"

/**
 *  Позже update будет работать в свой потоке
 */
void ui::Ui::update(void) const
{
    using namespace common;

    CommandId id_cmd = cui_core_.GetUserInput();

    Message input_msg = Module::take_input_msg_internal();

    // cui_core_.ProcessEvent( input_msg );

    // Message output_msg = cui_core_.Update( id_cmd );

    Module::push_output_msg_internal( output_msg );
}