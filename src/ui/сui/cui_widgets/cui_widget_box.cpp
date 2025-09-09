#include "cui_widget_box.h"

#include <algorithm>

// #include "cui_lib.h"
// #include "cui_label.h"
// #include "cui_dialog.h"
// #include "cui_entry.h"

extern "C"
{
#include "cdk/curdefs.h"
#include "cdk_objs.h"
}

namespace cui
{

// constexpr int MAX_Widget_IN_MANAGER = 20;

// // constexpr char KEY_ESC = 27; //используется для выхода из работы виджета

void WidgetBox::OnAddChild(Widget *child)
{
    childrens_.emplace_back(child);
}

void WidgetBox::OnRemoveChild(Widget *child)
{
    auto it = std::find(childrens_.begin(), childrens_.end(), child);
    if ( it != childrens_.end() ) 
        childrens_.erase(it);
}

cui::WidgetBox::WidgetBox(Widget *parent)
    : Widget(parent)
{
}

int WidgetBox::width(void)
{
    return width_;
}

int WidgetBox::height(void)
{
    return height_;
}

void cui::WidgetBox::draw(void)
{
    for(const auto wdgt : childrens_)

        wdgt->draw();
}

void WidgetBox::hide(void)
{
    for(const auto wdgt : childrens_)
        wdgt->hide();
}

IterWdgt WidgetBox::CreateIterator(void)
{
    return Widget::create_iterator<VectorIterator>(childrens_);
}

WidgetBox::~WidgetBox()
{
    for(auto wdgt : childrens_)
    {
        this->RemoveChild( wdgt );
        delete wdgt;
    }
}

// void cui::WidgetBox::add_child(Widget *child)
// {
//     children_.push_back(child);
// }

// it_wdgt WidgetBox::children(void)
// {
//     return children_.begin();
// }

// Widget *cui::WidgetBox::screen(void)
// {
//     return screen_;
// }

// void WidgetBox::correct_activ_Widget(void)
// {
//     if ( children_.empty() ) 
//         return;

//     if ( activ_Widget_ == children_.end() )
//         activ_Widget_ = children_.begin();

//     if ( !(*activ_Widget_)->active_ )
//     {
//         auto tmp_activ_Widget = activ_Widget_;
//         do
//         {
//             activ_Widget_++;

//             if ( activ_Widget_ == children_.end() )
//                 activ_Widget_ = children_.begin();
//         }
//         while( activ_Widget_ != tmp_activ_Widget && ( !(*activ_Widget_)->active_ ) );
//     }
// }

// int cui::WidgetBox::key_input(void)
// {
//     int ret = 1;
        
//     switch (key_)
//     {
//         case KEY_ESC: is_run_ = false; ret = 0; break;
//         case KEY_TAB: set_next_Widget();        break;
//         default:
//             break;
//     }

//     return ret;
// }


// void WidgetBox::activate(unsigned int*)
// {
//     is_run_ = true;

//     if ( children_.empty() ) 
//         return;

//     activ_Widget_ = children_.begin();
    
//     correct_activ_Widget();

//     this->screen_->refresh();

//     this->draw();

//     int tmp_key = 0;    
//     while(is_run_)
//     {
//         if ( (tmp_key=wgetch(stdscr)) > 0 )
//         {
//             // std::cerr << "key: " << tmp_key  <<" |"<<KEY_ESC<< std::endl;
//             key_ = tmp_key;
//             // key_ = 'k';
//             switch (key_)
//             {
//                 // case '\r': case '\n': key_ = KEY_ENTER;     break;
//                 case '\t':               key_ = KEY_TAB;       break;
//                 // case DELETE:          key_ = KEY_DC;        break;
//                 case '\b': case DELETE:  key_ = KEY_BACKSPACE; break;
//                 // case CDK_BEGOFLINE:   key_ = KEY_HOME;      break;
//                 // case CDK_ENDOFLINE:   key_ = KEY_END;       break;
//                 // case CDK_FORCHAR:     key_ = KEY_RIGHT;     break;
//                 // case CDK_BACKCHAR:    key_ = KEY_LEFT;      break;
//                 // case CDK_NEXT:        key_ = KEY_TAB;       break;
//                 // case CDK_PREV:        key_ = KEY_BTAB;      break;
//                 default: 
//                     break;
//             }
//             if ( key_input() )
//             {   
//                 // this->screen_->refresh(); //FIXME - заменить на обновление конкретного виджета
//                 if ( (*activ_Widget_)->active_ )
//                 {
//                     (*activ_Widget_)->activate(&key_);
//                 }
//             }
//         }

//         if ( tmp_key == ERR)
//             napms(30);
//     }
// }

// void cui::WidgetBox::set_next_Widget(void)
// {
//     activ_Widget_++;

//     correct_activ_Widget();
// }


}//namespace cui
