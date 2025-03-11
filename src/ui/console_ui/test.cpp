#include "cui_lib.h"
#include "cui_dialog.h"
#include "cui_screen.h"
#include "cui_label.h"

#include "pos_widget.h"
#include "pos_lib.h"

#include <iostream>
#include <memory>

using namespace std;
using namespace cui;
using namespace pos;

int main( )
{
    Message msg("<C></U>Dialog Widget Demo| |<C>The dialog widget allows the programmer to create|<C>a popup dialog box with buttons." 
                    "The dialog box|<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>|<R>and even be right justified.|"
                    "<L>and left.|gfgdfgdfgdfg");
    Message buttn("</B/2>Ok|</B16>Cancel|</B16>Hello");

    CUIScreen screen;

    shared_ptr<Widget> wdgt_label (new CUILabel(screen, msg, 10, 30, true, false));
    shared_ptr<Widget> wdgt_dialog(new CUIDialog(screen, msg, buttn, 70, 0, true, true, true ));

    Window window(FRAME_KANBAB::FRAME_INIT);

    window.add_widget(wdgt_dialog);
    window.add_widget(wdgt_label);

    window.update();

    for(const auto& tmp : window.get_widgets())
    {
        tmp.get()->draw();
    }
}