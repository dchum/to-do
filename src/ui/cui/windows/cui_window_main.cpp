#include "cui_window_main.h"

#include <iostream>
#include <cassert>

#include "cui_label.h"
#include "cui_slider.h"
#include "cui_lib.h"
#include "cui_radio.h"
#include "cui_entry.h"

#include "add_new_task.h"
#include "none_command.h"

cui::WindowMain::WindowMain(CUIScreen &screen)
    : Window(screen)
{

}

// cui::Command& cui::WindowMain::get_command_binding(unsigned int key)
// {
//     for (const auto& [k, ptr] : bindings_) {
//         assert(ptr != nullptr && "unique_ptr is null!");
//     }
    
//     return *(bindings_.at( key ));
//     // if ( bindings_.count( key )>0 )
//     // else
//     //     return *(bindings_.at( '?' ));
// }

// void cui::WindowMain::init_bindigs_keys(void)
// {    
//     // bindings_[CTRL('n')] = std::make_unique<cui::AddNewTask>( screen() );
//     // bindings_[CTRL('n')] = Command<CommandId::CreateTask>;
// }

void cui::WindowMain::init()
{
    cui::Message msgLabelName("</B>Kanban: task traker</B>");
    cui::Message msgLabelSupport("</B>F1<!B>: Add columns  </B>Ctrl+n<!B>: New task  </B>Esc<!B>: Quit");
    cui::Message msgLabelDescription("TASK: ~\
    Date:  ~\
    Status: ~\
    Tags:  ~\
    Description: ");

    cui::Message msgLabelBACKLOG ("<C></B>BACKLOG</B>");
    cui::Message msgLabelPROGRESS("<C></B>IN PROGRESS</B>");
    cui::Message msgLabelDONE    ("<C></B>DONE</B>");

    cui::Message msgSliderHello_("<C>progress");
    cui::Message msgSliderText_(" ");

    cui::Message msgRadioBACKLOG("No task");
    cui::Message msgRadioPROGRESS("No task");
    cui::Message msgRadioDONE("No task");

    AddChild<CUISlider>(40, 3, msgSliderHello_, msgSliderText_, 50);
    AddChild<CUILabel> (msgLabelName,        1,   0, false, false );
    AddChild<CUILabel> (msgLabelDescription, 3,  50, false, false);
    AddChild<CUILabel> (msgLabelSupport,     1, 100, false, false);
    AddChild<CUIRadio> ( 2, 20, 10, 30, msgLabelBACKLOG, msgRadioBACKLOG,' ');
    AddChild<CUIRadio> (35, 20, 10, 30, msgLabelPROGRESS, msgRadioPROGRESS,' ');
    AddChild<CUIRadio> (70, 20, 10, 30, msgLabelDONE, msgRadioDONE,' ');

    RegisterCommand(CTRL('n'), CommandId::CreateTask);
}

std::optional<CommandMessage> cui::WindowMain::update(int key)
{
    auto cmd = GetCommandId( key );
    
    cui::commands::Execute( cmd, screen(), queue_message_ui_ );

    if ( queue_message_ui_.size() ) {
        auto mes = queue_message_ui_.front();
        queue_message_ui_.pop();

        return CommandMessage::Create( HeaderMessage{.id = 0, .version = 1}, 
                                       cmd, mes );
    }
    else
        return std::nullopt;
}