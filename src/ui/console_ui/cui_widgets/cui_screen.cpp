#include "cui_screen.h"

namespace cui
{

cui::CUIScreen::CUIScreen( void )
    :Widget(nullptr),
    screen_( initCDKScreen (nullptr) )
{   
    initCDKColor ();
    
    getmaxyx(screen_->window, height_, width_);

    keypad (stdscr, TRUE);
}

cui::CUIScreen::~CUIScreen()
{ 
    destroyCDKScreen(screen_);
    endCDK();
    ExitProgram (EXIT_SUCCESS);
}

void cui::CUIScreen::refresh(void)
{
    refreshCDKScreen(screen_);
}

void CUIScreen::draw(void)
{
    for ( const auto wdgt: children_ )
        wdgt->draw();
}

void CUIScreen::hide(void)
{
    eraseCDKScreen(screen_);
}

void cui::CUIScreen::add_child(Widget * child)
{
    children_.push_back(child);
}

c_it_wdgt cui::CUIScreen::children(void)
{
    return children_.cbegin();
}

Widget *CUIScreen::screen(void)
{
    return this;
}

int CUIScreen::width()
{
    return width_;
}

int CUIScreen::height()
{
    return height_;
}


}
