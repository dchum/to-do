#include "cui_scroll_list.h"

#include <stdexcept>
#include <iostream>

#include "cui_screen.h"

// cui::CUIScrollList::CUIScrollList(CUIScreen& screen, int x, int y, int width, int height, Message &title, Message &list, 
//                         int choiceCharacter, int spos, int highlight, int defaultItem, bool box, bool shadow)
//     : Widget(screen, std::make_unique<RelativeSurface>(x, y, width, height)),
//     radio_(nullptr)
// {   
// 	auto tl = CStringArray( title );
// 	auto ls = CStringArray( list );

//     // std::cerr << ls.size() << " " << tl.size();

//     radio_ = newCDKRadio(screen.get(),
//                         Widget::x0(), Widget::y0(), spos,  Widget::height(),  Widget::width(), 
//                         (*tl.data()), ls.data(), ls.size(), 
//                         choiceCharacter, defaultItem, highlight, box, shadow);

//     if ( radio_ == nullptr ) 
//         throw std::runtime_error("CUIScrollList: Error new radio_");
// }

cui::CUIScrollList::CUIScrollList(CUIScreen &screen, int x, int y, Alignment al, int width, int height, Message &title, Message &list, bool is_has_numbers, chtype highlight, bool box, bool shadow)
    :Widget(screen, std::make_unique<RelativeSurface>(x, y, width, height)),
    scroll_list_(nullptr)
{
   	auto tl = CStringArray( title );
	auto ls = CStringArray( list ); 

    scroll_list_ = newCDKScroll( screen.get(), Widget::x0(), Widget::y0(), static_cast<int> ( al ),
                                 Widget::height(),  Widget::width(), 
                                 (*tl.data()), ls.data(), ls.size(), 
                                 is_has_numbers, highlight, box, shadow );
}

cui::CUIScrollList::~CUIScrollList()
{
    destroyCDKScroll(scroll_list_);
}

void cui::CUIScrollList::draw(void)
{
    drawCDKScroll(scroll_list_, ObjOf(scroll_list_)->box);
}

void cui::CUIScrollList::hide(void)
{
    eraseCDKScroll(scroll_list_);
}

void cui::CUIScrollList::addItem(const char *text)
{
    addCDKScrollItem( scroll_list_, text );
}
