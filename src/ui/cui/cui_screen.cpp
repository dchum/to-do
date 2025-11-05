#include "cui_screen.h"
#include <algorithm>

namespace cui
{

cui::CUIScreen::CUIScreen( void )
    :Widget(nullptr, nullptr),
    screen_( initCDKScreen (nullptr) )
{   
    initCDKColor ();
    
    keypad (stdscr, TRUE);
    int w, h;
    getmaxyx(stdscr, h, w);
    Widget::size_ = {0, 0, w, h};
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

int CUIScreen::width(void) const noexcept
{
    int w, h;
    getmaxyx(stdscr, h, w);
    return w;
}

int CUIScreen::height(void) const noexcept
{
    int w, h;
    getmaxyx(stdscr, h, w);
    return h;
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
