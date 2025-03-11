#include "cui_label.h"

#include <stdexcept>


cui::CUILabel::CUILabel(CUIScreen &cdkscreen, Message &mes, int x, int y, bool box, bool shadow)
	: Widget(Rect{x, y, 0, 0}),
	  label_(NULL)
{
    label_ = newCDKLabel(cdkscreen.get(), x, y, (CDK_CSTRING2) mes.get(), mes.count(), box, shadow );

    if ( label_ == NULL)
        throw std::runtime_error("CUILabel: Error new label_");
}

cui::CUILabel::~CUILabel()
{
    destroyCDKLabel (label_);
}

int cui::CUILabel::draw(void)
{
    activateCDKLabel (label_, NULL);
    // waitCDKLabel (label_, ' ');
    return 0;
}
