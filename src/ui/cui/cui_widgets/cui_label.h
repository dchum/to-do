#pragma once


extern "C" 
{ 
#include "cdk/cdkscreen.h"//FIXME - все ли эти заголовочные файлы нужны
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
        CUILabel(CUIScreen& screen, Message& mes, int x, int y, 
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