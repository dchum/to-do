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

cui::Size cui::FixedSurface::ComputeSize(int , int)
{
    return {std::max<int>(0, x_), std::max<int>(0, y_), std::max<int>(1, width_), std::max<int>(1, height_)};
}

cui::RelativeSurface::RelativeSurface(float x, float y, int width, int height)
:Surface(),
rel_x_(x), rel_y_(y), rel_width_(width), rel_height_(height)
{
}

cui::Size cui::RelativeSurface::ComputeSize(int parent_width, int parent_height)
{
    width_ = parent_width  * rel_width_ / 100.f;
    height_= parent_height * rel_height_/ 100.f;

    x_ = parent_width  * rel_x_ / 100.f;
    y_ = parent_height * rel_y_ / 100.f;

    return {std::max<int>(0, x_), std::max<int>(0, y_), std::max<int>(1, width_), std::max<int>(1, height_)};
}
