#include "add_new_task.h"

#include "cui_entry.h"
#include "cui_lib.h"

cui::AddNewTask::AddNewTask( Widget &target, const std::string &title, const std::string &label )
    :title_( title ), label_( label ), target_( target )
{
}

void cui::AddNewTask::Execute()
{
    CUIEntry entry( target_.get_screen(), title_, label_, 0, 0, 40, true, false );
    
    entry.move( Alignment::Center, Alignment::Center );
    entry.draw();

    target_.handle( reinterpret_cast<uint*>( entry.handle( nullptr ) ) );
}