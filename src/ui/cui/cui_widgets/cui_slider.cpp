#include "cui_slider.h"

#include <stdexcept>

#include "cui_screen.h"

namespace cui
{

cui::CUISlider::CUISlider(Widget *parent, int x, int y, Message &title, Message &label, int fieldWidth, unsigned int fillerCharacter, int currentValue, int lowValue, int highValue, int increment, int fastIncrement, bool box, bool shadow)
    : Widget(parent, std::make_unique<RelativeSurface>(x, y, fieldWidth, parent->height())),
    slider_(nullptr)
{
    slider_ = newCDKSlider(parent->screen(), Widget::x0(), Widget::y0(), 
                            *title.get_msg(), *label.get_msg(), 
                            fillerCharacter,  Widget::width(), 
                            currentValue, lowValue, highValue, 
                            increment, fastIncrement, box, shadow);

    if ( slider_ == nullptr)
        throw std::runtime_error("CUISlider: Error new slider_");
}

cui::CUISlider::~CUISlider()
{
    destroyCDKSlider(slider_);
}

void CUISlider::draw(void)
{
    drawCDKSlider(slider_, ObjOf(slider_)->box);
}

void CUISlider::hide(void)
{
    eraseCDKSlider(slider_);
}

// void CUISlider::activate(unsigned int *key)
// {
//     slider_->obj.hasFocus = 1;
//     activateCDKSlider (slider_, key);
// }

}