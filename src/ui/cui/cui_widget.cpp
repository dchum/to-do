#include "cui_widget.h"

#include <iostream>

namespace cui
{
    Widget::Widget( CUIScreen& screen, WidgetGeometry geometry )
    : id_(new_id++),
      screen_(screen)
    {
        compute_size( geometry );
    }

    ssize_t Widget::get_id(void) const noexcept
    {
        return id_;
    }

    int Widget::x0(void)
    {
        return actual_size_.x;
    }

    int Widget::y0(void)
    {
        return actual_size_.y;
    }

    int Widget::width(void) const noexcept
    {
        return actual_size_.width;
    }

    int  Widget::height ( void ) const noexcept
    {
        return actual_size_.height;
    }

    void Widget::compute_size( const WidgetGeometry& geometry)
    {
        switch (geometry.mode)
        {
            case LayoutMode::Absolute:
                actual_size_ = { std::max<int>(0, geometry.rect.x),     std::max<int>(0, geometry.rect.y), 
                                 std::max<int>(1, geometry.rect.width), std::max<int>(1, geometry.rect.height) };
                break;

            case LayoutMode::Relative:
                float width = geometry.rect.width  * screen_.width()  / 100.f;
                float height = geometry.rect.height * screen_.height() / 100.f;

                float x = geometry.rect.x * screen_.width() /100.f;
                float y = geometry.rect.y * screen_.height()/100.f;

                actual_size_ = {std::max<int>(0, x), std::max<int>(0, y), std::max<int>(1, width), std::max<int>(1, height)};
                break;
        }
    }

    Widget::~Widget()
    {
    }

}//namespace cui
