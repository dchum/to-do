#pragma once

extern "C" 
{ 
#include "cdk/label.h" 
}

#include "pos_widget.h"
#include "cui_screen.h"
#include "cui_lib.h"

namespace cui
{

using pos::Widget;

class CUILabel : public Widget
{
private:
    CDKLABEL *label_;

public:
    CUILabel() = delete;
    CUILabel(CUIScreen& cdkscreen, Message& mes, int x, int y, bool box = true, bool shadow = true);

    ~CUILabel();

    int draw( void ) override;
};

}