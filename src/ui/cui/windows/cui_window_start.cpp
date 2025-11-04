#include "cui_window_start.h"

#include "cui_label.h"
#include "cui_lib.h"

cui::Message msgHello(
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


cui::Message msgText(
R"(Task Management, Fast. ^ ^
Press ENTER to start ^
Press S for Settings ^
Press Q to quit)"
);

cui::WindowStart::WindowStart(Widget *parent)
    :Window(parent)
{
    AddChild<CUILabel>( msgHello, 35, 30, false, false ) ;
    AddChild<CUILabel>( msgText,  45, 60, false, false ) ;
}