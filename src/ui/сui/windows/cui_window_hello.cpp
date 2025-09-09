#include "cui_window_hello.h"

#include "cui_label.h"
#include "cui_lib.h"

cui::Message msgHello(
R"(                                                           ^
</B>__________ ________              ________  ________       ^
</B>|\___   ___\\   __  \            |\   ___ \|\   __  \     ^
</B>\|___ \  \_\ \  \|\  \  _________\ \  \_|\ \ \  \|\  \    ^
</B>     \ \  \ \ \  \\\  \|\_________\ \  \ \\ \ \  \\\  \   ^
</B>      \ \  \ \ \  \\\  \|_________|\ \  \_\\ \ \  \\\  \  ^
</B>       \ \__\ \ \_______\           \ \_______\ \_______\ ^
</B>        \|__|  \|_______|            \|_______|\|_______| ^
                                        To-Do CLI v0.1.0 | Created by: @dchum )"
);


cui::Message msgText(
R"(Task Management, Fast. ^ ^
Press ENTER to start ^
Press S for Settings ^
Press Q to quit)"
);

cui::WindowHello::WindowHello(Widget *parent)
    :Window(parent)
{
    wdgt_box.AddChild( new CUILabel(&wdgt_box, msgHello, 50, 15, false, false) ) ;
    wdgt_box.AddChild( new CUILabel(&wdgt_box, msgText,  70, 30, false, false) ) ;  
}

void cui::WindowHello::OnAddChild(Widget *child)
{
    wdgt_box.AddChild(child);
}

void cui::WindowHello::OnRemoveChild(Widget *child)
{
    wdgt_box.RemoveChild(child);
}
