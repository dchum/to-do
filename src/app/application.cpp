#include "application.h"

void app::Application::init()
    :ui_core_(queue_ui2core)
{

}

void app::Application::exec()
{
    while ( is_running_ ) {

        ui_core_.HandleInput();

        // if ( queue_ui2core.size() )

        // CommandMessage command;
        // command = ui_core_.HandleInput();


        // model_core_.update( command );
        // ui_core_.update( model_core_.process() );

        // if ( command )
        //     queue_model.push_back( command );

        // while ( (event = queue_view.pop()) != NoEvent ) {
        //     view.update( event );
        // }
    }
}
