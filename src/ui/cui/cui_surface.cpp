#include "cui_surface.h"

#include <algorithm>
#include <iostream>

cui::Surface::Surface( void )
{
}

cui::FixedSurface::FixedSurface(float x, float y, int width, int height)
:Surface(),
x_(x), y_(y), width_(width), height_(height)
{
}

cui::Size cui::FixedSurface::ComputeSize( Size )
{
    return {std::max<int>(0, x_), std::max<int>(0, y_), std::max<int>(1, width_), std::max<int>(1, height_)};
}

cui::RelativeSurface::RelativeSurface(float x, float y, int width, int height)
:Surface(),
rel_x_(x), rel_y_(y), rel_width_(width), rel_height_(height)
{
}

cui::Size cui::RelativeSurface::ComputeSize( Size real_size)
{
    width_ = real_size.width  * rel_width_ / 100.f;
    height_= real_size.height * rel_height_/ 100.f;

    x_ = real_size.x +  rel_x_ * real_size.width /100.f;
    y_ = real_size.y +  rel_y_ * real_size.height/100.f;

    return {std::max<int>(0, x_), std::max<int>(0, y_), std::max<int>(1, width_), std::max<int>(1, height_)};
}
