#pragma once

extern "C"
{
#include "cdk/scroll.h"
}

#include "cui_lib.h"
#include "cui_widget.h"

namespace cui
{

class CUIScrollList : public Widget
{
private :
    CDKSCROLL *scroll_list_;

public:
    CUIScrollList() = delete;
    CUIScrollList( CUIScreen& screen, int x, int y, Alignment al,
            int width, int height, 
            Message& title, Message& list,
            bool is_has_numbers,
            chtype highlight,
            bool box = false, bool shadow = false);

    CUIScrollList ( const CUIScrollList& ) = delete;
    CUIScrollList& operator=(const CUIScrollList&) = delete;

    ~CUIScrollList();

public:
    void draw   ( void ) override;
    void hide   ( void ) override;
public:
    void addItem( const char * text );
};

}//namespace cui