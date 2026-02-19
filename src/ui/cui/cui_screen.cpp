#include "cui_screen.h"
#include <algorithm>

#include "iterator/list_iter.h"

namespace cui
{

cui::CUIScreen::CUIScreen( void )
    :screen_( initCDKScreen (nullptr) )
{   
    initCDKColor ();
    
    keypad (screen_->window, TRUE);
    curs_set(0);
}

cui::CUIScreen::~CUIScreen()
{ 
    destroyCDKScreen(screen_.release());
    endCDK();
    ExitProgram (EXIT_SUCCESS);
}

int CUIScreen::width(void) const noexcept
{
    return getmaxx(stdscr);
}

int CUIScreen::height(void) const noexcept
{
    return getmaxy(stdscr);
}

}
