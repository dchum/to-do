#include "cui_widget.h"

#include <iostream>

namespace cui
{
    Widget::Widget(Widget* parent, std::unique_ptr<Surface> surface_imp)
    : parent_(parent),
      id_(new_id++), 
      surface_imp_(std::move(surface_imp))
    {
        if ( parent_ )
        {
            parent->AddChild(this);
        }
        if ( surface_imp_ )
            size_ = surface_imp_->ComputeSize(parent->size_.width, parent->size_.height);
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

    // void Widget::SetParent( Widget *new_parent )
    // {
    //     if ( parent_ == new_parent || !new_parent )
    //         return;

    //     if ( parent_ )
    //     {
    //         parent_->RemoveChild(this);
    //     }
        
    //     new_parent->AddChild(this);
    // }

    // void Widget::RemoveParent( )
    // {
    //     if ( parent_)
    //     {
    //         parent_->RemoveChild(this);
    //         parent_=nullptr;
    //     }
    // }

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

    int Widget::x0(void)
    {
        return size_.x;
    }

    int Widget::y0(void)
    {
        return size_.y;
    }

    int Widget::width(void) const noexcept
    {
        return size_.width;
    }

    int  Widget::height ( void ) const noexcept
    {
        return size_.height;
    }

    Widget::~Widget()
    {
        // RemoveParent();//FIXME - корректно разрывать связи с родителями
    }

}//namespace cui
