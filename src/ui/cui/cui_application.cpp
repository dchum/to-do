#include "cui_application.h"

#include <iostream>
#include <time.h>

#include "cui_window_main.h"
#include "cui_window_setting.h"
#include "cui_window_start.h"
#include "cui_entry.h"

cui::Message msgLabelBACKLOG1 ("<C></B>BACKLOG</B>");

void cui::CUIApplication::add_new_columns(void)
{
    screen_.AddChild<CUIEntry> (msgLabelBACKLOG1,  msgLabelBACKLOG1, 50, 50, 50)->draw();
}

cui::CUIApplication::CUIApplication(void)
    : Application(), _is_run_(true)
{
    dynamic_cast<WindowMain*>( screen_.AddChild<WindowMain>() )->init();
}

cui::CUIApplication::~CUIApplication()
{

}

void cui::CUIApplication::exec(void)
{
    static int x = 0;
    if ( !x )
    {
        screen_.refresh();
        screen_.draw();
        x = 1;
    }

    int key_ = -1;
    
    while ( _is_run_ )
    {
        if ( (key_=wgetch(screen_.get()->window)) > 0 )
        {
            // std::cerr << key_ << std::endl;
            // key_ = 'k';
            switch (key_)
            {
                // case '\r': case '\n': key_ = KEY_ENTER;     break;
                case '\t':               key_ = KEY_TAB;       break;
                // case DELETE:          key_ = KEY_DC;        break;
                case '\b': case DELETE:  key_ = KEY_BACKSPACE; break;
                // case CDK_BEGOFLINE:   key_ = KEY_HOME;      break;
                // case CDK_ENDOFLINE:   key_ = KEY_END;       break;
                // case CDK_FORCHAR:     key_ = KEY_RIGHT;     break;
                // case CDK_BACKCHAR:    key_ = KEY_LEFT;      break;
                // case CDK_NEXT:        key_ = KEY_TAB;       break;
                // case CDK_PREV:        key_ = KEY_BTAB;      break;
                case KEY_F1:        add_new_columns();      break;
                default: 
                    break;
            }
            // screen_.draw();
        }
        // screen_.refresh();
        struct  timespec ts = {0, 1000};
        nanosleep(&ts, NULL);
    }
}
