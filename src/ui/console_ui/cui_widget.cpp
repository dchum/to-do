#include "cui_widget.h"

namespace cui
{
Widget::Widget(Widget *parent)
: parent_(parent),  active_(true)
{
    if ( parent )
        parent->add_child(this);
}

const Widget& cui::Widget::parent()
{
    return *parent_;
}

}
