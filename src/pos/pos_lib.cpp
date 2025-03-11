#include "pos_lib.h"

#include <algorithm>
#include <memory>

namespace pos
{

pos::Window::Window(FRAME_KANBAB frame)
    :frame_(frame){   }

void pos::Window::add_widget(std::shared_ptr<Widget> wdgt)
{
    window_.push_back(wdgt);
}

void Window::update(void) noexcept
{
    std::sort(window_.begin(), window_.end(), 
             [](const std::shared_ptr<Widget> lhs, std::shared_ptr<Widget> rhs)
             {
                return lhs.get()->get_priority() < rhs.get()->get_priority();
             });
}

const std::vector<std::shared_ptr<Widget>>& Window::get_widgets(void) const noexcept
{
    return window_;
}

const std::vector<std::shared_ptr<Widget>>& Window::get_widgets(void) noexcept
{
    return static_cast<const Window&>(*this).get_widgets();
}

}

