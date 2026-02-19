#include "cui_application.h"

#include <iostream>
#include <time.h>

#include "cui_window_main.h"
#include "cui_window_setting.h"
#include "cui_window_start.h"
#include "cui_entry.h"

cui::Message msgLabelBACKLOG1 ("<C></B>BACKLOG</B>");

cui::CUIApplication::CUIApplication(void)
    : Application(), _is_run_(true)
{
    windows_.push_back( new WindowMain( screen_ ) );

    for ( auto w : windows_ ) {
        w->init();
    }
}

void cui::CUIApplication::exec(void)
{
    int key_ = 0;

    auto current_window = windows_.front();

    refreshCDKScreen ( screen_.get() );
    current_window->draw();

    while ( _is_run_ )
    {
        if ( (key_=wgetch( screen_.get()->window ) ) > 0 )
        {
            // std::cout << "__" << key_  << std::endl;
            switch (key_)
            {
                // case '\r': case '\n': key_ = KEY_ENTER;     break;
                // case '\t':            key_ = KEY_TAB;       break;
                // case DELETE:          key_ = KEY_BACKSPACE; break;
                case '\b': case 127: case 330:  key_ = KEY_BACKSPACE; break;
                // case CDK_BEGOFLINE:   key_ = KEY_HOME;      break;
                // case CDK_ENDOFLINE:   key_ = KEY_END;       break;
                // case CDK_FORCHAR:     key_ = KEY_RIGHT;     break;
                // case CDK_BACKCHAR:    key_ = KEY_LEFT;      break;
                // case CDK_NEXT:        key_ = KEY_TAB;       break;
                // case CDK_PREV:        key_ = KEY_BTAB;      break;
                // case KEY_F1:        add_new_columns();      break;
                case KEY_ESC:       _is_run_ = false;       break;
                default: 
                    break;
            }
            current_window->handle( reinterpret_cast<uint*>(&key_) );
            current_window->draw();
        }
        // wrefresh( screen_.get()->window );
        struct  timespec ts = {0, 1000};
        nanosleep(&ts, NULL);
    }
}
