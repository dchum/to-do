#pragma once

extern "C" 
{ 
#include "cdk/cdkscreen.h"
#include "cdk/binding.h"
#include "cdk/cdk_objs.h"
#include "cdk/label.h" 
}

#include "cui_widget.h"
#include "cui_lib.h"

namespace cui
{
    class CUILabel : public Widget
    {
    private:
        CDKLABEL *label_;

    public:
        CUILabel() = delete;
        CUILabel(Widget* parent, Message& mes, int x, int y, 
                bool box = true, bool shadow = true);

        CUILabel ( const CUILabel& ) = delete;
        CUILabel& operator=(const CUILabel&) = delete;

        ~CUILabel();

    public:
        void draw  ( void ) override;
        void hide  ( void ) override;
        // void activate( unsigned int* ) override;
    };
}