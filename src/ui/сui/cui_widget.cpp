#include "cui_widget.h"

#include <iostream>

namespace cui
{
    Widget::Widget(Widget* parent)
    : parent_(parent),
      id_(new_id++)
    {
        if ( parent_ )
        {
            parent->AddChild(this);
            set_size(100, 100);
        }
        else
        {
            size.percent_of_height_ = 100;
            size.percent_of_width_  = 100;
        }
    }

    void Widget::SetParentInternal(Widget *new_parent)
    {
        parent_ = new_parent;
    }

    void Widget::OnAddChild(Widget *child)
    {
        (void)child;
    }

    void Widget::OnRemoveChild(Widget *child)
    {
        (void)child;
    }

    void Widget::AddChild( Widget * child )
    {
        if ( !child ) return;
        if ( child->parent_)
            child->parent_->RemoveChild(child);
        OnAddChild(child);
        child->SetParentInternal(this);
    }

    void Widget::RemoveChild(Widget * child)
    {
        if ( !child ) return;
        OnRemoveChild(child);
        child->SetParentInternal(nullptr);
    }

    void Widget::SetParent( Widget *new_parent )
    {
        if ( parent_ == new_parent || !new_parent )
            return;

        if ( parent_ )
        {
            parent_->RemoveChild(this);
        }
        
        new_parent->AddChild(this);
    }

    void Widget::RemoveParent( )
    {
        if ( parent_)
        {
            parent_->RemoveChild(this);
            parent_=nullptr;
        }
    }

    Widget *Widget::getParent(void)
    {
        return parent_;
    }

    CDKSCREEN *Widget::screen()
    {
        return ( parent_ ? parent_->screen() : nullptr );
    }

    ssize_t Widget::get_id(void) const noexcept
    {
        return id_;
    }

    IterWdgt Widget::CreateIterator( )
    {   
        return create_iterator<NULLIterWdgt>();
    }

    int  Widget::width ( void ) const noexcept
    {
        return size.width_;
    }

    int  Widget::height ( void ) const noexcept
    {
        return size.height_;
    }

    void Widget::set_size(int w_percent, int h_percent) noexcept
    {
        size.percent_of_height_ = h_percent;
        size.percent_of_width_  = w_percent;

        size.width_ =parent_->width()*w_percent/100;
        size.height_=parent_->height()*h_percent/100;
    }

    void Widget::set_internal_size(int w, int h) noexcept
    {
        size.height_ = h;
        size.width_ = w;
    }

    std::tuple<int, int> Widget::get_size( void ) const noexcept
    {
        int w_real = size.width_*size.percent_of_width_/100;
        int h_real = size.height_*size.percent_of_height_/100;
        return {w_real, h_real};
    }

    Widget::~Widget()
    {
        RemoveParent();
        
    }

}//namespace cui
