#pragma once

extern "C"
{
#include "cdk/radio.h"
}

#include "cui_lib.h"
#include "cui_widget.h"
//FIXME - расширить до возможности указывать в качестве шаблона, какой тип выводить
namespace cui
{

    class CUIRadio : public Widget
    {
    private :
        CDKRADIO *radio_;

    public:
        CUIRadio() = delete;
        CUIRadio( CUIScreen& screen, int x, int y,
                int width, int height, 
                Message& title, Message& list,
                int choiceCharacter = '#', 
                int spos = NONE,
                int highlight = A_REVERSE, int defaultItem = 1,
                bool box = false, bool shadow = false);

        CUIRadio ( const CUIRadio& ) = delete;
        CUIRadio& operator=(const CUIRadio&) = delete;

        ~CUIRadio();
    
    public:
        void draw   ( void ) override;
        void hide   ( void ) override;
    };

}//namespace cui