#pragma once

#include <cstdint>
#include <variant>
#include <ostream>
#include <array>
#include <stdexcept>
#include <assert.h>

// KeyEvent — это логическое сочетание: базовая клавиша плюс модификаторы

namespace cui {

enum ModifierKey : uint8_t {
    None  = 0,
    Shift = 1 << 0,
    Ctrl  = 1 << 1,
    Alt   = 1 << 2,
    // Meta  = 1 << 3
};

using Modifiers = uint8_t;

using CharCode = uint32_t; // 32-битный символ Unicode 

enum class NamedKey {
    None,
    Backspace,
    Tab,
    Enter,
    Escape,
    Space,
    Up,
    Down,
    Left,
    Right,
    Home,
    End,
    PageUp,
    PageDown,
    Insert,
    Delete,
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12
};

enum class KeyKind 
{
    KEY_INVALID = 0,
    KEY_CHAR,
    KEY_NAMED,
};

struct KeyEvent 
{
    KeyKind kind;
    Modifiers mods;

    std::variant<CharCode, NamedKey> base;

    //FIXME - чехарда с конструкторами
    
    KeyEvent () :kind(KeyKind::KEY_INVALID)
    { }

    KeyEvent (KeyKind) : KeyEvent ()
    {}

    KeyEvent (CharCode ch, ModifierKey m = ModifierKey::None) : kind(KeyKind::KEY_CHAR), mods(m), base(ch)
    {}

    KeyEvent (NamedKey nk, ModifierKey m = ModifierKey::None) : kind(KeyKind::KEY_NAMED), mods(m), base(nk)
    {}
};

};//namespace cui

inline std::ostream& operator<<(std::ostream& out, cui::NamedKey k) 
{
    static constexpr std::array<std::string_view, 28> names = {
        "None", "Backspace", "Tab", "Enter", "Escape", "Space",
        "Up", "Down", "Left", "Right",
        "Home", "End", "PageUp", "PageDown", "Insert", "Delete",
        "F1", "F2", "F3", "F4", "F5", "F6",
        "F7", "F8", "F9", "F10", "F11", "F12"
    };

    static_assert(names.size() == static_cast<std::size_t>(cui::NamedKey::F12) + 1, "names does not correspond enum NamedKey");

    const auto i = static_cast<std::size_t>(k);
    if (i < names.size())
        out << names[i];
    else
        out << "Unknown";

    return out << ':' << static_cast<int>(k);
}

inline std::ostream& operator<<(std::ostream& out, cui::KeyKind k)
{
    switch (k) 
    {
        case cui::KeyKind::KEY_INVALID: return out << "KEY_INVALID";
        case cui::KeyKind::KEY_CHAR:    return out << "KEY_CHAR";
        case cui::KeyKind::KEY_NAMED:   return out << "KEY_NAMED";

        default: throw std::logic_error(__func__);
    }
}

inline std::ostream& operator << ( std::ostream& out, cui::KeyEvent key )
{
    out << "[" << key.kind << ":";

    if ( key.mods != 0 )
    {
        out << ":";
        bool first = true;
        auto print_mod = [&](cui::ModifierKey flag, const char* name) 
        {
            if (key.mods & flag) 
            {
                out << name;
                out << "+";
                first = false;
            }
        };

        print_mod(cui::ModifierKey::Shift, "Shift");
        print_mod(cui::ModifierKey::Ctrl, "Ctrl");
        print_mod(cui::ModifierKey::Alt, "Alt");
        
        if (first) out << "UnknownMods(" << static_cast<int>(key.mods) << ")";
    }
    
    std::visit([&out](const auto& v) { out << v; }, key.base);

    out << "]";

    return out;
}
