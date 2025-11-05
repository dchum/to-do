#include "cui_label.h"

#include <stdexcept>
#include <memory>

#include "cui_screen.h"


cui::CUILabel::CUILabel(Widget* parent, Message &mes, int x, int y, bool box, bool shadow)
	: Widget(parent, std::make_unique<RelativeSurface>(x, y, parent->width(), parent->height())),
	  label_(nullptr)
{
    label_ = newCDKLabel( parent->screen(), Widget::x0(), Widget::y0(), 
                          (CDK_CSTRING2) mes.get_msg(), mes.count(), 
                          box, shadow );

    if ( label_ == nullptr)
        throw std::runtime_error("CUILabel: Error new label_");
}

cui::CUILabel::~CUILabel()
{
    destroyCDKLabel (label_);
}

void cui::CUILabel::draw(void)
{
    drawCDKLabel (label_, ObjOf (label_)->box);
}

// void cui::CUILabel::activate(unsigned int* key)
// {
//     (void*)key++;
//     waitCDKLabel (label_, '\0');
// }

void cui::CUILabel::hide(void)
{
    eraseCDKLabel(label_);
}
