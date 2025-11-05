#include "cui_border.h"

#include <iostream>

cui::CUIBorder::CUIBorder(Widget *parent, int x, int y, int width, int height, bool top, bool left, bool right, bool bottom_)
    : Widget(parent, std::make_unique<RelativeSurface>(x, y, width, height)),
      win_(nullptr),
      top_(top), left_(left), right_(right), bottom_(bottom_)
{
    win_ = newwin (Widget::height(), Widget::width(), Widget::y0(), Widget::x0());
}

cui::CUIBorder::~CUIBorder()
{
    delwin(win_);
}

void cui::CUIBorder::draw(void)
{
    int h = height();
    int w = width();

    if (top_)    mvwhline(win_, 0, 0, ACS_HLINE, w);
    if (bottom_) mvwhline(win_, h - 1, 0, ACS_HLINE, w);
    if (left_)   mvwvline(win_, 0, 0, ACS_VLINE, h);
    if (right_)  mvwvline(win_, 0, w - 1, ACS_VLINE, h);

    if (top_ && left_)     mvwaddch(win_, 0, 0, ACS_ULCORNER);
    if (top_ && right_)    mvwaddch(win_, 0, w - 1, ACS_URCORNER);
    if (bottom_ && left_)  mvwaddch(win_, h - 1, 0, ACS_LLCORNER);
    if (bottom_ && right_) mvwaddch(win_, h - 1, w - 1, ACS_LRCORNER);
        
    wrefresh(win_);
}

void cui::CUIBorder::hide(void)
{
    werase (win_);
    wrefresh (win_);
}

void cui::CUIBorder::ShowBorder(bool is_show)
{
    if ( is_show )
        this->ShowBorder(true, true, true, true);
    else
        this->ShowBorder(false, false, false, false);
}

void cui::CUIBorder::ShowBorder(bool top, bool left, bool right, bool bottom)
{
    top_    = top;
    bottom_ = bottom;
    right_  = right;
    left_   = left;
}
