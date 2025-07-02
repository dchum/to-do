#pragma once

extern "C"
{
#include "cdk/radio.h"
}

#include "cui_lib.h"
#include "cui_widget.h"

namespace cui
{

class CUIRadio : public Widget
{
private :
    CDKRADIO *radio_;

    int width_,
        height_;

public:
    CUIRadio() = delete;
    CUIRadio( Widget* parent, int x, int y,
              int width, int height, 
              Message& title, Message& list, int count_list,
              int choiceCharacter = '#', 
              int spos = RIGHT,
              int highlight = A_REVERSE, int defaultItem = 1,
              bool box = true, bool shadow = true);

    CUIRadio ( const CUIRadio& ) = delete;
    CUIRadio& operator=(const CUIRadio&) = delete;

    ~CUIRadio();

    int width ( void ) override;
    int height( void ) override;

    void draw    ( void ) override;
    void hide    ( void ) override;
    void activate( unsigned int* ) override;
};

}