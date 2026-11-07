#include "input.h"

#include <ncurses.h>

namespace cui {

/*! @brief Parses a key code into a key specification */
KeyEvent parse_key_spec( int status, int32_t keycode );

    
KeyEvent parse_key_spec( int status, int32_t keycode)
{
    if ( status == ERR )
    {
        return KeyKind::KEY_INVALID;
    }

    KeyEvent res{};
    res.mods = ModifierKey::None;

    if (status == OK) {
        uint32_t ch = keycode;
        
        if (ch == 27) { // Escape
            res.kind = cui::KeyKind::KEY_NAMED;
            res.base = cui::NamedKey::Escape;
            return res;
        }
        else if (ch == 32 )
        {
            res.kind = cui::KeyKind::KEY_NAMED;
            res.base = cui::NamedKey::Space;
            return res;
        }
        else if (ch == 9) { // Tab
            res.kind = cui::KeyKind::KEY_NAMED;
            res.base = cui::NamedKey::Tab;
            return res;
        }
        else if (ch == 10 || ch == 13) {
            res.kind = cui::KeyKind::KEY_NAMED;
            res.base = cui::NamedKey::Enter;
            return res;
        }
        else if (ch == 127 || ch == 8) {
            res.kind = cui::KeyKind::KEY_NAMED;
            res.base = cui::NamedKey::Backspace;
            return res;
        }

        if (ch >= 1 && ch <= 26) {
            res.kind = cui::KeyKind::KEY_CHAR;

            char letter = 'a' + (ch - 1);

            res.base = static_cast<cui::CharCode>(letter);
            res.mods |= cui::ModifierKey::Ctrl;
            return res;
        }

        if (ch == 0) {
             res.kind = cui::KeyKind::KEY_NAMED;
             res.base = cui::NamedKey::Space;
             res.mods |= cui::ModifierKey::Ctrl;
             return res;
        }

        if (ch >= 'A' && ch <= 'Z') {
            res.mods |= cui::ModifierKey::Shift;
            res.base = static_cast<cui::CharCode>(std::tolower(ch)); 
        }

        res.kind = cui::KeyKind::KEY_CHAR;
        res.base = ch;
        
        return res;
    }

    if (status == KEY_CODE_YES)
    {
        switch(keycode) 
        {
            case KEY_IC:        res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::Insert;    break;
            case KEY_HOME:      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::Home;      break;
            case KEY_END:       res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::End;       break;
            case KEY_PPAGE:     res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::PageUp;    break;
            case KEY_NPAGE:     res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::PageDown;  break;
            case KEY_DC:        res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::Delete;    break;   
            case KEY_BACKSPACE: res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::Backspace; break;
            case KEY_UP:        res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::Up;        break;
            case KEY_DOWN:      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::Down;      break;
            case KEY_LEFT:      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::Left;      break;
            case KEY_RIGHT:     res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::Right;     break;
            case KEY_F(1):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F1;        break;
            case KEY_F(2):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F2;        break;
            case KEY_F(3):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F3;        break;
            case KEY_F(4):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F4;        break;
            case KEY_F(5):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F5;        break;
            case KEY_F(6):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F6;        break;
            case KEY_F(7):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F7;        break;
            case KEY_F(8):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F8;        break;
            case KEY_F(9):      res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F9;        break;
            case KEY_F(10):     res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F10;       break;
            case KEY_F(11):     res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F11;       break;
            case KEY_F(12):     res.kind=KeyKind::KEY_NAMED; res.base = NamedKey::F12;       break;

            default:
                res.kind = KeyKind::KEY_INVALID;
        }
        return res;
    }

    res.kind = KeyKind::KEY_INVALID;
    return res;
}

KeyEvent readKeyEvent(void)
{
    wint_t wc;

    int rc = get_wch(&wc);

    return parse_key_spec( rc, wc );    
}

}; // namespace cui