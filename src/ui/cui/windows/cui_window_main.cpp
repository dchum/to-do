#include "cui_window_main.h"

#include "cui_label.h"
#include "cui_slider.h"
#include "cui_lib.h"
#include "cui_radio.h"
#include "cui_entry.h"
#include "add_new_task.h"

#include <iostream>
#include <cassert>

cui::WindowMain::WindowMain(CUIScreen& screen)
    :Window(screen)
{

}

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

    cui::Message msgHello_(
    R"(                                                           ~
    </B>__________ ________              ________  ________       ~
    </B>|\___   ___\\   __  \            |\   ___ \|\   __  \     ~
    </B>\|___ \  \_\ \  \|\  \  _________\ \  \_|\ \ \  \|\  \    ~
    </B>     \ \  \ \ \  \\\  \|\_________\ \  \ \\ \ \  \\\  \   ~
    </B>      \ \  \ \ \  \\\  \|_________|\ \  \_\\ \ \  \\\  \  ~
    </B>       \ \__\ \ \_______\           \ \_______\ \_______\ ~
    </B>        \|__|  \|_______|            \|_______|\|_______| ~
                                            To-Do CLI v0.1.0 | Created by: @dchum )"//FIXME - вынести номер версии в отдельный макрос
    );
    
    AddChild<CUISlider> (40, 3, msgSliderHello_, msgSliderText_, 50);
    AddChild<CUILabel>  (msgLabelName,        1,   0, false, false );
    AddChild<CUILabel> (msgLabelDescription, 3,  50, false, false);
    AddChild<CUILabel> (msgLabelSupport,     1, 100, false, false);
    target = AddChild<CUIRadio> ( 2, 20, 10, 30, msgLabelBACKLOG, msgRadioBACKLOG,' ');
    AddChild<CUIRadio> (35, 20, 10, 30, msgLabelPROGRESS, msgRadioPROGRESS,' ');
    AddChild<CUIRadio> (70, 20, 10, 30, msgLabelDONE, msgRadioDONE,' ');
    AddChild<CUILabel> (msgHello_,  40, 70, false, false);
    // assert( typeid( CUIEntry) == typeid( target ) );
    // widgets.push_back( AddChild<CUIEntry> (msgLabelBACKLOG,  msgLabelBACKLOG, 50, 50, 50) );
}

char* cui::WindowMain::handle( uint* key )
{
    if ( key  ) {
        AddNewTask command( *target, "<C></B>Enter a\n<C></B>directory name.", " " ); 
        command.Execute();
    }

    return nullptr;
}
