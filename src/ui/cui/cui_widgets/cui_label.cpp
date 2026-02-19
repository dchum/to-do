#include "cui_label.h"

#include <stdexcept>
#include <memory>

#include "cui_screen.h"


cui::CUILabel::CUILabel(CUIScreen& screen, Message &mes, int x, int y, bool box, bool shadow)
	: Widget(screen, std::make_unique<RelativeSurface>(x, y, 100, 100)),
	  label_(nullptr)
{
    auto data = CStringArray( mes );
    label_ = newCDKLabel( screen.get(), Widget::x0(), Widget::y0(), 
                          (CDK_CSTRING2) data.data(), data.size(), 
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
