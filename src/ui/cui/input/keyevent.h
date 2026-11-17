#pragma once

#include <cstdint>
#include <variant>
#include <ostream>
#include <array>
#include <stdexcept>
#include <assert.h>

#include "magic_enum.hpp"
#include "magic_enum_iostream.hpp" // для автоматического вывода в std::cout

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

    KeyEvent () :kind(KeyKind::KEY_INVALID), mods(0), base( CharCode(0) )
    { }

    KeyEvent (CharCode ch, Modifiers m = 0) : kind(KeyKind::KEY_CHAR), mods(m), base(ch)
    {}

    KeyEvent (NamedKey nk, Modifiers m = 0) : kind(KeyKind::KEY_NAMED), mods(m), base(nk)
    {}
};

inline bool operator==(const KeyEvent& lhs, const KeyEvent& rhs) {
    return lhs.kind == rhs.kind && lhs.mods == rhs.mods && lhs.base == rhs.base;
}

inline bool operator<(const KeyEvent& lhs, const KeyEvent& rhs) {
    if (lhs.kind != rhs.kind) {
        return lhs.kind < rhs.kind;
    }
    if (lhs.mods != rhs.mods) {
        return lhs.mods < rhs.mods;
    }
    return lhs.base < rhs.base;
}

};//namespace cui




inline std::ostream& operator<<(std::ostream& out, cui::NamedKey k) 
{
    using magic_enum::iostream_operators::operator<<;
    return out << k << ':' << static_cast<int>(k);
}

inline std::ostream& operator<<(std::ostream& out, cui::KeyKind k)
{
    using magic_enum::iostream_operators::operator<<;
    return out << k;
}

inline std::ostream& operator << ( std::ostream& out, const cui::KeyEvent& key )
{
    out << "[" << key.kind << ":";

    if ( key.mods != 0 )
    {
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
