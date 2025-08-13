#include "cui_widget.h"

namespace cui
{
    
    Widget::Widget(Widget *parent)
    : parent_(parent), iter_(nullptr)
    {
        if ( parent )
            parent->AddChild(this);
    }

    void Widget::AddChild( Widget * )
    {

    }

    CDKSCREEN *Widget::screen()
    {
        return ( parent_ ? parent_->screen() : nullptr );
    }

    IterWidgets* Widget::CreateIterator( )
    {   
        // if ( !iter_ )
        //     iter_ = new NullIterWidgets();

        // return *(iter_);
        return create_iterator<NullIterWidgets>();
    }

    Widget::~Widget()
    {
        delete parent_;
        
        if ( iter_ )
            delete iter_;
    }

}//namespace cui
