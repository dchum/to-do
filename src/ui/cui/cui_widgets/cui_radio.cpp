#include "cui_radio.h"

#include <stdexcept>
#include <iostream>

#include "cui_screen.h"

cui::CUIRadio::CUIRadio(CUIScreen& screen, int x, int y, int width, int height, Message &title, Message &list, 
                        int choiceCharacter, int spos, int highlight, int defaultItem, bool box, bool shadow)
    : Widget(screen, std::make_unique<RelativeSurface>(x, y, width, height)),
    radio_(nullptr)
{   
	auto tl = CStringArray( title );
	auto ls = CStringArray( list );

    std::cerr << ls.size() << " " << tl.size();

    radio_ = newCDKRadio(screen.get(),
                        Widget::x0(), Widget::y0(), spos,  Widget::height(),  Widget::width(), 
                        (*tl.data()), ls.data(), ls.size(), 
                        choiceCharacter, defaultItem, highlight, box, shadow);

    if ( radio_ == nullptr ) 
        throw std::runtime_error("CUIRadio: Error new radio_");
}

cui::CUIRadio::~CUIRadio()
{
    destroyCDKRadio(radio_);
}

void cui::CUIRadio::draw(void)
{
    drawCDKRadio(radio_, ObjOf(radio_)->box);
}

void cui::CUIRadio::hide(void)
{
    eraseCDKRadio(radio_);
}

