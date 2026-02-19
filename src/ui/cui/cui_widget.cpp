#include "cui_widget.h"

#include <iostream>

namespace cui
{
    Widget::Widget( CUIScreen& screen, std::unique_ptr<Surface> surface_imp )
    : id_(new_id++),
      surface_imp_( std::move(surface_imp) ),
      screen_(screen)
    {
        if ( surface_imp_ )
            size_ = surface_imp_->ComputeSize( {0, 0, screen.width(), screen.height()} );
    }

    ssize_t Widget::get_id(void) const noexcept
    {
        return id_;
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
    }

}//namespace cui
