#include "cui_screen.h"
#include <iostream>

namespace cui
{

cui::CUIScreen::CUIScreen( void )
    :Widget(nullptr),
    screen_( initCDKScreen (nullptr) )
{   
    Widget::set_internal_size(COLS, LINES);
    // initCDKColor ();
    
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

IterWdgt CUIScreen::CreateIterator(void)
{
    return Widget::create_iterator<ScreenIter>(children_);
}

CDKSCREEN *CUIScreen::screen()
{
    return screen_;
}

void CUIScreen::OnAddChild(Widget *child)
{
    children_.emplace_back(child);
}

void CUIScreen::OnRemoveChild(Widget *child)
{
    auto it = std::find(children_.begin(), children_.end(), child);
    if ( it != children_.end() ) 
        children_.erase(it);
}


}
