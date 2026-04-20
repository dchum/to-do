#include "add_new_task.h"

#include "cui_entry.h"
#include "cui_lib.h"


void cui::AddNewTask::Execute( CUIScreen& screen, std::queue<MessagePayload>& queue_message_ui_  )
{
    CUIEntry entry( screen, title_, label_, 0, 0, 40, true, false );
    
    entry.move( Alignment::Center, Alignment::Center );
    entry.draw();

    char* input = entry.handle_input( nullptr );

    queue_message_ui_.push( MessageAddNewTask{.name_new_task = input} );
}