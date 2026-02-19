#pragma once

extern "C"
{
#include "cdk/slider.h"
}

#include "cui_widget.h"
#include "cui_lib.h"

namespace cui
{

    class CUISlider : public Widget
    {
    private:
        CDKSLIDER *slider_;

    public:
        CUISlider() = delete;

        CUISlider(CUIScreen& screen, int x, int y, 
                Message& title, Message& label,
                int fieldWidth,
                unsigned int fillerCharacter = A_REVERSE | COLOR_PAIR (29) | ' ',
                int currentValue = 0,
                int lowValue     = 0,
                int highValue    = 100,
                int increment    = 1,
                int fastIncrement= 10,
                bool box = false, bool shadow = false);

        CUISlider ( const CUISlider& ) = delete;
        CUISlider& operator=(const CUISlider&) = delete;

        ~CUISlider();

    public:
        void draw  ( void ) override;
        void hide  ( void ) override;
        // void activate( unsigned int* ) override;
    };

}//namespace cui