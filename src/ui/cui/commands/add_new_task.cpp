#include "add_new_task.h"

#include "cui_entry.h"
#include "cui_lib.h"


cui::AddNewTask::AddNewTask( CUIScreen& screen )
    :title_( "<C>New task" ), label_( "name task:" ), screen_( screen )
{
}

CommandMessage cui::AddNewTask::Execute()
{
    CUIEntry entry( screen_, title_, label_, 0, 0, 40, true, false );
    
    entry.move( Alignment::Center, Alignment::Center );
    entry.draw();

    char* input = entry.handle_input( nullptr );

    return CommandMessage{
        .id = 0,
        .payload = CmdAddNewTask{.name_new_task = input }
    };
}