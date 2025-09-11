#pragma once

extern "C" 
{ 
#include "cdk/entry.h" 
}

#include "cui_widget.h"
#include "cui_lib.h"

namespace cui
{
    class CUIEntry: public Widget
    {
    private:
        CDKENTRY *entry_;

    public:
        CUIEntry() = delete;
        CUIEntry(Widget* parent, Message& title, Message& label, int x, int y, int fieldWidth,
                bool box = true, bool shadow = true);
        
        CUIEntry (const CUIEntry&) = delete;
        CUIEntry& operator=(const CUIEntry&) = delete;
        
        ~CUIEntry();

    public:
        void draw  ( void ) override;
        void hide  ( void ) override;
        // void activate( unsigned int* ) override;
    };

}//namespace cui