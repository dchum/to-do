#include "cui_radio.h"

#include <stdexcept>
#include <iostream>

#include "cui_screen.h"

cui::CUIRadio::CUIRadio(Widget *parent, int x, int y, int width, int height, Message &title, Message &list, 
int count_list, int choiceCharacter, int spos, int highlight, int defaultItem, bool box, bool shadow)
    :Widget(parent),
    radio_(nullptr)
{   
    Widget::set_size(width, height);
    radio_ = newCDKRadio(parent->screen(),
                        x, y, spos, Widget::height(), Widget::width(), 
                        (*title.get_msg()), list.get_msg(), count_list, 
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

// void cui::CUIRadio::activate(unsigned int *key)
// {
//     radio_->obj.hasFocus = 1;
//     activateCDKRadio(radio_, key);
// }
