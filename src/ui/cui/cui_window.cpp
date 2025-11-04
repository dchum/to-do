#include "cui_window.h"

#include "cui_widget_box.h"

cui::Window::Window(Widget *parent)
    :Widget(parent, std::make_unique<FixedSurface>(0, 0, parent->width(), parent->height())),
    wdgt_box(parent)
{
    
}

void cui::Window::draw(void)
{
    auto iter = wdgt_box.CreateIterator();
    for ( iter->Begin(); !iter->IsDone(); iter->Next() )
        iter->CurrentValue().draw();
}

void cui::Window::hide(void)
{
}

void cui::Window::OnAddChild(Widget *child)
{
    wdgt_box.AddChild(child);
}

void cui::Window::OnRemoveChild(Widget *child)
{
    wdgt_box.RemoveChild(child);
}
