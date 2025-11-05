#include "cui_dialog.h"

extern "C"
{
#include "cdk.h"
#include "cdk_params.h"
}

#include <stdexcept>


cui::CUIDialog::CUIDialog(Widget* parent, Message& message, Message& buttons, int x, int y, bool box, bool separator, bool shadow)
	: Widget(parent, std::make_unique<RelativeSurface>(x, y, parent->width(), parent->height())),
	  dialog_(nullptr)
{
	dialog_ = newCDKDialog (parent->screen(), Widget::x0(), Widget::y0(),
				(CDK_CSTRING2) message.get_msg(), message.count(),
				(CDK_CSTRING2) buttons.get_msg(), buttons.count(),
				COLOR_PAIR (buttons.count()) | A_REVERSE,
				box       ? 1:0,
				separator ? 1:0,
				shadow    ? 1:0);
				
	if ( dialog_ == nullptr )
		throw std::runtime_error("CUIDialog: Error new dialog_");
}

cui::CUIDialog::~CUIDialog()
{
    destroyCDKDialog(dialog_);
}

void cui::CUIDialog::draw(void)
{
	drawCDKDialog (dialog_, ObjOf (dialog_)->box);
}

void cui::CUIDialog::hide(void)
{
	eraseCDKDialog(dialog_);
}

// void cui::CUIDialog::activate( unsigned int* key )
// {
// 	dialog_->obj.hasFocus = 1;
// 	activateCDKDialog(dialog_, key);
// }
