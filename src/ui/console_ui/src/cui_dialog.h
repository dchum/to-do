#pragma once

extern "C"
{
#include "cdk/dialog.h"
}


#include "pos_widget.h"
#include "cui_screen.h"
#include "cui_lib.h"

namespace cui
{

using pos::Widget;

class CUIDialog : public Widget
{

private:
    CDKDIALOG* dialog_;

public:
    CUIDialog() = delete;
    CUIDialog( CUIScreen& cdkscreen, 
               Message& mes,
               Message& buttons,
               int x, int y,
               bool box = true, bool separator = true, bool shadow = true,
               int priority = 1 );
    
    ~CUIDialog(){   destroyCDKDialog(dialog_);   }

    CUIDialog& operator=(const CUIDialog& other) = delete;
    CUIDialog( CUIDialog& other) = delete;

    int draw( void ) override;

};
}
