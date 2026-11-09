#include "input.h"

#include <ncurses.h>

namespace cui {

/*! @brief Parses a key code into a key specification */
KeyEvent parse_key_spec( int status, int32_t keycode)
{
    if ( status == ERR )
    {
        return KeyEvent();
    }

    if (status == OK) {
        uint32_t ch = keycode;
        
        if (ch == 27) { // Escape
            return KeyEvent(cui::NamedKey::Escape);
        }
        else if (ch == 32 )
        {
            return KeyEvent(cui::NamedKey::Space);
        }
        else if (ch == 9) { // Tab
            return KeyEvent(cui::NamedKey::Tab);
        }
        else if (ch == 10 || ch == 13) {
            return KeyEvent(cui::NamedKey::Enter);
        }
        else if (ch == 127 || ch == 8) {
            return KeyEvent(cui::NamedKey::Backspace);
        }

        if (ch >= 1 && ch <= 26) {
            char letter = 'a' + (ch - 1);
            return KeyEvent(letter, cui::ModifierKey::Ctrl);
        }

        if (ch == 0) {
            return KeyEvent(cui::NamedKey::Space, cui::ModifierKey::Ctrl);
        }

        cui::Modifiers mods = ModifierKey::None;
        cui::CharCode base = static_cast<cui::CharCode>(ch);

        if (ch >= 'A' && ch <= 'Z') {
            mods = cui::ModifierKey::Shift;
            base = std::tolower(ch);
        }

        return KeyEvent(base, mods);
    }

    if (status == KEY_CODE_YES)
    {
        switch(keycode) 
        {
            case KEY_IC:        return KeyEvent(NamedKey::Insert);    
            case KEY_HOME:      return KeyEvent(NamedKey::Home);      
            case KEY_END:       return KeyEvent(NamedKey::End);       
            case KEY_PPAGE:     return KeyEvent(NamedKey::PageUp);    
            case KEY_NPAGE:     return KeyEvent(NamedKey::PageDown);  
            case KEY_DC:        return KeyEvent(NamedKey::Delete);       
            case KEY_BACKSPACE: return KeyEvent(NamedKey::Backspace); 
            case KEY_UP:        return KeyEvent(NamedKey::Up);        
            case KEY_DOWN:      return KeyEvent(NamedKey::Down);      
            case KEY_LEFT:      return KeyEvent(NamedKey::Left);      
            case KEY_RIGHT:     return KeyEvent(NamedKey::Right);     
            case KEY_F(1):      return KeyEvent(NamedKey::F1);        
            case KEY_F(2):      return KeyEvent(NamedKey::F2);        
            case KEY_F(3):      return KeyEvent(NamedKey::F3);        
            case KEY_F(4):      return KeyEvent(NamedKey::F4);        
            case KEY_F(5):      return KeyEvent(NamedKey::F5);        
            case KEY_F(6):      return KeyEvent(NamedKey::F6);        
            case KEY_F(7):      return KeyEvent(NamedKey::F7);        
            case KEY_F(8):      return KeyEvent(NamedKey::F8);        
            case KEY_F(9):      return KeyEvent(NamedKey::F9);        
            case KEY_F(10):     return KeyEvent(NamedKey::F10);       
            case KEY_F(11):     return KeyEvent(NamedKey::F11);       
            case KEY_F(12):     return KeyEvent(NamedKey::F12);       

            default:
                return KeyEvent();
        }
    }

    return KeyEvent();
}

KeyEvent readKeyEvent(void)
{
    wint_t wc;

    int rc = get_wch(&wc);

    return parse_key_spec( rc, wc );    
}

KeyEvent parse_key_spec(std::string_view keySpec)
{
    return KeyEvent();
}

}; // namespace cui