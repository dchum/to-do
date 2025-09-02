#include "cui_window_hello.h"

#include "cui_label.h"
#include "cui_lib.h"

cui::Message msgHello(
#if 1
R"(                                                           ^
</B>__________ ________              ________  ________       ^
</B>|\___   ___\\   __  \            |\   ___ \|\   __  \     ^
</B>\|___ \  \_\ \  \|\  \  _________\ \  \_|\ \ \  \|\  \    ^
</B>     \ \  \ \ \  \\\  \|\_________\ \  \ \\ \ \  \\\  \   ^
</B>      \ \  \ \ \  \\\  \|_________|\ \  \_\\ \ \  \\\  \  ^
</B>       \ \__\ \ \_______\           \ \_______\ \_______\ ^
</B>        \|__|  \|_______|            \|_______|\|_______| ^
                                        To-Do CLI v0.1.0 | Created by: @dchum )"
#elif 0
R"(
</R>--------<!R>╗ ------╗       ------╗  ------╗ ^
╚══</R>██<!R>╔══╝██╔═══██╗      ██╔══██╗██╔═══██╗^
   </R>██<!R>║   ██║   ██║█████╗██║  ██║██║   ██║^
   </R>██<!R>║   ██║   ██║╚════╝██║  ██║██║   ██║^
   </R>██<!R>║   ╚------╔╝      ------╔╝╚------╔╝^
   ╚═╝    ╚═════╝       ╚═════╝  ╚═════╝ @
)"
#endif
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
    auto lb1 = new CUILabel(&wdgtbox, msgHello, 50, 15, false, false);
    auto lb2 = new CUILabel(&wdgtbox, msgText,  70, 30, false, false);  
}