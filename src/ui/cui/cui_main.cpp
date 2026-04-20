#include "cui_main.h"

#include <iostream>
#include <time.h>

#include "cui_window_main.h"
#include "cui_window_setting.h"
#include "cui_window_start.h"
#include "cui_entry.h"

cui::Message msgLabelBACKLOG1 ("<C></B>BACKLOG</B>");

cui::CUICore::CUICore(void)
{
    windows_.push_back( new WindowMain( screen_ ) );

    for ( auto w : windows_ ) {
        w->init();
    }
    
    refreshCDKScreen ( screen_.get() );
    auto current_window = windows_.front();
    current_window->draw();
}

std::optional<CommandMessage> cui::CUICore::handleInput( void )
{
    std::optional<CommandMessage> ret = std::nullopt;

    auto current_window = windows_.front();
    keypad(stdscr, TRUE);
    int key_ = 0;
    if ( (key_= wgetch( screen_.get()->window ) ) > 0 )
    {
        // std::cout << key_ << std::endl;
        // exit(0);
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
            // case KEY_ESC:       _is_run_ = false;       break;
            case 14: 
                current_window->update( key_ );
                current_window->draw();
                break;
        }
    }
 
    return ret;
}