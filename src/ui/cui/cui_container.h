#pragma once

#include <memory>
#include <list>

#include "cui_widget.h"
#include "cui_screen.h"
#include "cui_border.h"

#include "cdk/binding.h"
#include "cdk/curdefs.h"
#include "cdk/cdk_objs.h"
#include "cdk/cdkscreen.h"


namespace cui
{

class Container : public Widget
{
    std::list<Widget*> childrens_;

    CUIBorder* bord_;//FIXME - использовать умный указатель

    // void OnAddChild   (Widget* child);
    // void OnRemoveChild(Widget* child);

    template <typename Iter, typename... Args>
    inline IterWdgt create_iterator(Args&&... args)
    {
        return std::make_unique<Iter>( std::forward<Args>(args)... );
    }

public:
    Container( CUIScreen& screen );
    Container( CUIScreen& screen, int x, int y, int width, int height);
    
    ~Container();

public:
    template<typename T, typename... Args>
    Widget* AddChild ( Args&&... args     );
    void    AddChild ( Widget* child      );
    void RemoveChild ( Widget* child      );

    void ShowBorder( bool is_show );
    void ShowBorder( bool top, bool left, bool right, bool bottom );

    void draw  ( void ) override;
    void hide  ( void ) override;
    
    IterWdgt CreateIterator( void );

public:
    CUIScreen& screen( void ){ return Widget::screen_; }
};

template <typename T, typename... Args>
Widget* Container::AddChild(Args &&...args)
{
    Widget* wdgt = new T(this->screen(), std::forward<Args>(args)...);
    Container::AddChild(wdgt);
    return wdgt;
}

}//namespace cui
