#include "cui_widget.h"

namespace cui
{
    Widget::Widget(Widget *parent)
    : parent_(parent),
      id_(new_id++)
    {
        if ( parent_ )
            parent->AddChild(this);
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

    Widget::~Widget()
    {
        RemoveParent();
        
    }

}//namespace cui
