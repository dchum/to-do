#include "application.h"

void app::Application::init()
{
    router_.AddModule( &ui_core_    );
    router_.AddModule( &model_core_ );
}

void app::Application::exec()
{
    while ( is_running_ ) 
    {
        router_.update();

    }
}
