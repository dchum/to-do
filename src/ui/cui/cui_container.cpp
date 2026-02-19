#include "cui_container.h"

#include <algorithm>


extern "C"
{
#include "cdk/curdefs.h"
#include "cdk_objs.h"
}

#include "iterator/list_iter.h"
#include <iostream>
namespace cui
{

cui::Container::Container( CUIScreen& screen )
    :Container(screen, 0, 0, 100, 100)
{
}

Container::Container( CUIScreen& screen, int x, int y, int width, int height)
    : Widget(screen, std::make_unique<RelativeSurface>(x, y, width, height)),
    bord_( new CUIBorder( screen, x, y, width, height ) )
{

}

void Container::AddChild( Widget * child )
{
    if ( !child ) return;
   
    childrens_.emplace_back(child);
}

void Container::RemoveChild(Widget * child)
{
    if ( !child ) return;
    
    auto it = std::find(childrens_.begin(), childrens_.end(), child);
    if ( it != childrens_.end() ) 
        childrens_.erase(it);
}

void Container::ShowBorder(bool is_show)
{
    bord_->ShowBorder(is_show);
}

void Container::ShowBorder(bool top, bool left, bool right, bool bottom)
{
    bord_->ShowBorder(top, left, right, bottom);
}

void cui::Container::draw(void)
{
    bord_->draw();
    for(const auto wdgt : childrens_)
    {
        wdgt->draw();
    }
}

void Container::hide(void)
{
    bord_->hide();
    for(const auto wdgt : childrens_)
        wdgt->hide();
}

IterWdgt Container::CreateIterator(void)
{
    return create_iterator<ListIterator>(childrens_);
}

Container::~Container()
{
    delete bord_;

    for ( auto it = childrens_.begin(); it != childrens_.end(); ++it ) 
    {
        delete (*it);
    }
}


// void cui::Container::add_child(Widget *child)
// {
//     children_.push_back(child);
// }

// it_wdgt Container::children(void)
// {
//     return children_.begin();
// }

// Widget *cui::Container::screen(void)
// {
//     return screen_;
// }

// void Container::correct_activ_Widget(void)
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

// int cui::Container::key_input(void)
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


// void Container::activate(unsigned int*)
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

// void cui::Container::set_next_Widget(void)
// {
//     activ_Widget_++;

//     correct_activ_Widget();
// }


}//namespace cui
