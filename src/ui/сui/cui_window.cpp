#include "cui_window.h"

#include "cui_widget_box.h"

cui::Window::Window(Widget *parent)
    :Widget(parent),
    wdgtbox(parent)
{
    
}

void cui::Window::draw(void)
{
    auto iter = wdgtbox.CreateIterator();
    for ( iter->Begin(); !iter->IsDone(); iter->Next() )
        iter->CurrentValue().draw();
}

void cui::Window::hide(void)
{
}
