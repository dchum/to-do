#include "application.h"


void app::Application::exec()
{
    while ( is_running_ ) {
        CommandMessage command;
        command = ui_core_.HandleInput();


        model_core_.update( command );
        ui_core_.update( model_core_.process() );

        // if ( command )
        //     queue_model.push_back( command );

        // while ( (event = queue_view.pop()) != NoEvent ) {
        //     view.update( event );
        // }
    }
}
