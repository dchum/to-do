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
    std::unique_ptr<CUIBorder> bord_;

public:
    Container( CUIScreen& screen );
    Container( CUIScreen& screen, int x, int y, int width, int height );
    
    virtual ~Container();

public:
    template<typename T, typename... Args>
    Widget* AddChild ( Args&&... args     );
    void    AddChild ( Widget* child      );
    void RemoveChild ( Widget* child      );

    void ShowBorder( bool is_show );
    void ShowBorder( bool top, bool left, bool right, bool bottom );

    void draw  ( void ) override;
    void hide  ( void ) override;
};

template <typename T, typename... Args>
Widget* Container::AddChild(Args &&...args)
{
    Widget* wdgt = new T(this->screen(), std::forward<Args>(args)...);
    this->AddChild(wdgt);
    return wdgt;
}

}//namespace cui
