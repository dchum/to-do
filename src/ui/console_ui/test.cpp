#include "cui_dialog.h"
#include "cui_screen.h"
#include "cui_lib.h"


using namespace std;
using namespace cui;

int main( )
{
    std::string mes("<C></U>Dialog Widget Demo| |<C>The dialog widget allows the programmer to create|<C>a popup dialog box with buttons." 
                    "The dialog box|<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>|<R>and even be right justified.|"
                    "<L>and left.|gfgdfgdfgdfg");

    std::string bt("</B/24>Ok|</B16>Cancel|</B16>Hello");

    Message msg(mes);
    Message buttn(bt);

    CUIScreen screen;

    CUIDialog dialog(screen, msg, buttn, 70, 0, true, true, true );

    dialog.draw();
}