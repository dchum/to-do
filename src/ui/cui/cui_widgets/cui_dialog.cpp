#include "cui_dialog.h"

extern "C"
{
#include "cdk.h"
#include "cdk_params.h"
}

#include <stdexcept>


cui::CUIDialog::CUIDialog(CUIScreen& screen, Message& message, Message& buttons, int x, int y, bool box, bool separator, bool shadow)
	: Widget(screen, std::make_unique<RelativeSurface>(x, y, screen.width(), screen.height())),
	  dialog_(nullptr)
{
	auto mes = CStringArray( message );
	auto bt  = CStringArray( buttons );

	dialog_ = newCDKDialog (screen.get(), Widget::x0(), Widget::y0(),
				(CDK_CSTRING2) mes.data(), mes.size(),
				(CDK_CSTRING2) bt.data(), bt.size(),
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
