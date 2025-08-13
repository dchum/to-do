#include "cui_radio.h"

#include <stdexcept>

#include "cui_screen.h"

cui::CUIRadio::CUIRadio(Widget *parent, int x, int y, int width, int height, Message &title, Message &list, 
int count_list, int choiceCharacter, int spos, int highlight, int defaultItem, bool box, bool shadow)
    :Widget(parent),
    radio_(nullptr)
{
    radio_ = newCDKRadio(parent->screen(),
                        x, y, spos, height, width, (*title.get_msg()), list.get_msg(), count_list, 
                        choiceCharacter, defaultItem, highlight, box, shadow);

    if ( radio_ == nullptr ) 
        throw std::runtime_error("CUIRadio: Error new radio_");
}

cui::CUIRadio::~CUIRadio()
{
    destroyCDKRadio(radio_);
}

int cui::CUIRadio::width(void)
{
    return width_;
}

int cui::CUIRadio::height(void)
{
    return height_;
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
