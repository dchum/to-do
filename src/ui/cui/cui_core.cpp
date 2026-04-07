#include "cui_core.h"

#include <iostream>
#include <time.h>

#include "cui_window_main.h"
#include "cui_window_setting.h"
#include "cui_window_start.h"
#include "cui_entry.h"

cui::Message msgLabelBACKLOG1 ("<C></B>BACKLOG</B>");

cui::CUICore::CUICore(void)
    : _is_run_(true)
{
    windows_.push_back( new WindowMain( screen_ ) );

    for ( auto w : windows_ ) {
        w->init();
    }
    
    refreshCDKScreen ( screen_.get() );
    auto current_window = windows_.front();
    current_window->draw();
}

CommandMessage cui::CUICore::handleInput( void )
{
    CommandMessage ret;

    auto current_window = windows_.front();
    
    int key_ = 0;
    if ( (key_= wgetch( screen_.get()->window ) ) > 0 )
    {
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
            case KEY_ESC:       _is_run_ = false;       break;
            case 'n': 
                ret = current_window->update( key_ );
                current_window->draw();
                break;
        }
    }

    return ret;
    // current_window->handle_input( reinterpret_cast<uint*>(&key_) );
    // current_window->draw();
}
