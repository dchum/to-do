#include "cui_widget.h"

namespace cui
{
    
    Widget::Widget(Widget *parent)
    : parent_(parent), iter_(nullptr)
    {
        if ( parent )
            parent->AddChild(this);//FIXME - необходимо установить единый механизм добавления потомков
    }

    void Widget::AddChild( Widget * )
    {

    }

    CDKSCREEN *Widget::screen()
    {
        return ( parent_ ? parent_->screen() : nullptr );
    }


    IterWdgt Widget::CreateIterator( )
    {   
        return create_iterator<NULLIterWdgt>();
    }

    Widget::~Widget()
    {

    }

}//namespace cui
