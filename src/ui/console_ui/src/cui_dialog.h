#pragma once
#include <utility>

extern "C"
{
#include "cdk/dialog.h"
}


#include "cui_screen.h"
#include "cui_lib.h"
#include "pos_window.h"

namespace cui
{

using pos::Window;
using std::string;

class CUIDialog : public Window
{

private:
    CDKDIALOG* dialog_;

public:

    CUIDialog( cui::CUIScreen& cdkscreen, 
               Message& mes,
               Message& buttons,
               int x, int y,
               bool box = true, bool separator = true, bool shadow = true );
    
    ~CUIDialog(){   destroyCDKDialog(dialog_);   }

    CUIDialog& operator=(const CUIDialog& other) = delete;
    CUIDialog( CUIDialog& other) = delete;

    int draw( void ) override;

};
}
