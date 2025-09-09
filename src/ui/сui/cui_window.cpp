#include "cui_window.h"

#include "cui_widget_box.h"

cui::Window::Window(Widget *parent)
    :Widget(parent),
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
