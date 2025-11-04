#pragma once

extern "C"
{
#include "cdk/dialog.h"
}


#include "cui_widget.h"
#include "cui_screen.h"
#include "cui_lib.h"

namespace cui
{
    class CUIDialog : public Widget
    {
    private:
        CDKDIALOG* dialog_;

    public:
        CUIDialog() = delete;
        CUIDialog( Widget* parent, 
                   Message& mes,
                   Message& buttons,
                   int x, int y,
                   bool separator = true, bool box = true, bool shadow = false );
        
        CUIDialog& operator=(const CUIDialog& other) = delete;
        CUIDialog( CUIDialog& other) = delete;

        ~CUIDialog();
        
    public:
        void draw  ( void ) override;
        void hide  ( void ) override;
        // void activate( unsigned int* ) override;
    };
}//namespace cui
