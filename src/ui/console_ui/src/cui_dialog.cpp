#include "cui_dialog.h"

extern "C"
{
#include "cdk.h"
#include "cdk_params.h"
}

#include <stdexcept>


cui::CUIDialog::CUIDialog(cui::CUIScreen& cdkscreen, Message& message, Message& buttons, int x, int y, bool box, bool separator, bool shadow)
	: Window(Rect{x, y, 0, 0}),
	  dialog_(NULL)
{
	dialog_ = newCDKDialog (cdkscreen.get(), x,y,
				(CDK_CSTRING2) message.get(), message.count(),
				(CDK_CSTRING2) buttons.get(), buttons.count(),
				COLOR_PAIR (2) | A_REVERSE,
				box       ? 1:0,
				separator ? 1:0,
				shadow    ? 1:0);
				
	if ( dialog_ == NULL )
		throw std::runtime_error("CUIDialog: Error new dialog_");
}

int cui::CUIDialog::draw(void)
{
	return activateCDKDialog (dialog_, NULL);
}
