#pragma once

#include <cstdint>
#include <variant>

// KeySpec — это логическое сочетание: базовая клавиша плюс модификаторы

enum class ModifierKey {
    None  = 0,
    Shift = 1 << 0,
    Ctrl  = 1 << 1,
    Alt   = 1 << 2,
    // Meta  = 1 << 3
};

using CharKey = uint32_t; // 32-битный символ Unicode 

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

struct KeySpec 
{
    KeyKind kind;
    ModifierKey mods;

    std::variant<CharKey, NamedKey> base;
};