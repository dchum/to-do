#include "key_input.h"

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
#if 0

namespace cui {

namespace detail {

inline std::string_view trim(std::string_view s) noexcept
{
    while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front())))
        s.remove_prefix(1);

    while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back())))
        s.remove_suffix(1);

    return s;
}

inline std::string lower_ascii(std::string_view s)
{
    std::string out;
    out.reserve(s.size());

    for (char c : s)
    {
        out.push_back(
            static_cast<char>(
                std::tolower(static_cast<unsigned char>(c))
            )
        );
    }

    return out;
}

inline Modifiers clear_shift(Modifiers m) noexcept
{
    return static_cast<Modifiers>(
        m & ~static_cast<unsigned>(ModifierKey::Shift)
    );
}

inline std::optional<NamedKey> parse_named_key(std::string_view s)
{
    const std::string n = lower_ascii(trim(s));

    if (n == "escape" || n == "esc")
        return NamedKey::Escape;

    if (n == "tab")
        return NamedKey::Tab;

    if (n == "enter" || n == "return" || n == "cr")
        return NamedKey::Enter;

    if (n == "backspace" || n == "bs")
        return NamedKey::Backspace;

    if (n == "space" || n == " ")
        return NamedKey::Space;

    if (n == "up" || n == "arrowup")
        return NamedKey::Up;

    if (n == "down" || n == "arrowdown")
        return NamedKey::Down;

    if (n == "left" || n == "arrowleft")
        return NamedKey::Left;

    if (n == "right" || n == "arrowright")
        return NamedKey::Right;

    if (n == "home")
        return NamedKey::Home;

    if (n == "end")
        return NamedKey::End;

    if (n == "pageup" || n == "pgup")
        return NamedKey::PageUp;

    if (n == "pagedown" || n == "pgdn")
        return NamedKey::PageDown;

    if (n == "insert" || n == "ins")
        return NamedKey::Insert;

    if (n == "delete" || n == "del")
        return NamedKey::Delete;

    // F1 ... F12
    if (n.size() >= 2 && n[0] == 'f')
    {
        int value = 0;
        bool has_digits = false;

        for (std::size_t i = 1; i < n.size(); ++i)
        {
            const unsigned char c = static_cast<unsigned char>(n[i]);

            if (!std::isdigit(c))
                return std::nullopt;

            has_digits = true;
            value = value * 10 + (c - '0');
        }

        if (has_digits && value >= 1 && value <= 12)
        {
            const int offset = value - 1;
            return static_cast<NamedKey>(
                static_cast<int>(NamedKey::F1) + offset
            );
        }
    }

    return std::nullopt;
}

inline std::optional<uint32_t> decode_utf8_char(std::string_view s) noexcept
{
    if (s.empty())
        return std::nullopt;

    const unsigned char b0 = static_cast<unsigned char>(s[0]);

    // ASCII
    if (b0 < 0x80)
    {
        if (s.size() != 1)
            return std::nullopt;

        return static_cast<uint32_t>(b0);
    }

    int len = 0;
    uint32_t cp = 0;

    if ((b0 & 0xE0) == 0xC0)
    {
        len = 2;
        cp = b0 & 0x1F;
    }
    else if ((b0 & 0xF0) == 0xE0)
    {
        len = 3;
        cp = b0 & 0x0F;
    }
    else if ((b0 & 0xF8) == 0xF0)
    {
        len = 4;
        cp = b0 & 0x07;
    }
    else
    {
        return std::nullopt;
    }

    if (s.size() != static_cast<std::size_t>(len))
        return std::nullopt;

    for (int i = 1; i < len; ++i)
    {
        const unsigned char b = static_cast<unsigned char>(s[i]);

        if ((b & 0xC0) != 0x80)
            return std::nullopt;

        cp = (cp << 6) | (b & 0x3F);
    }

    // Отклоняем overlong sequences.
    if (len == 2 && cp < 0x80)
        return std::nullopt;

    if (len == 3 && cp < 0x800)
        return std::nullopt;

    if (len == 4 && cp < 0x10000)
        return std::nullopt;

    // Суррогаты UTF-16 недопустимы в UTF-8.
    if (cp >= 0xD800 && cp <= 0xDFFF)
        return std::nullopt;

    if (cp > 0x10FFFF)
        return std::nullopt;

    return cp;
}

inline KeyEvent make_char_key(uint32_t cp, Modifiers mods) noexcept
{
    // Пробел в вашем runtime-парсере приводится к NamedKey::Space.
    // Значит и конфиг должен делать то же самое.
    if (cp == U' ')
    {
        mods = clear_shift(mods);
        return KeyEvent(NamedKey::Space, mods);
    }

    bool is_letter = false;
    uint32_t lower_cp = cp;

    // Быстрая ASCII-проверка.
    if (cp < 0x80)
    {
        const unsigned char c = static_cast<unsigned char>(cp);

        if (std::isalpha(c))
        {
            is_letter = true;
            lower_cp = static_cast<uint32_t>(
                std::tolower(c)
            );
        }
    }
    else
    {
        // Попытка обработать Unicode-буквы через wide-character API.
        // На Linux wchar_t обычно 32 бита, поэтому кириллица работает.
        if (cp <= static_cast<uint32_t>(std::numeric_limits<wchar_t>::max()))
        {
            const wchar_t w = static_cast<wchar_t>(cp);
            const std::wint_t ww = static_cast<std::wint_t>(w);

            if (std::iswalpha(ww))
            {
                is_letter = true;
                lower_cp = static_cast<uint32_t>(
                    std::towlower(ww)
                );
            }
        }
    }

    if (is_letter)
    {
        // Совместимость с legacy-терминалом:
        //
        // Ctrl+Shift+p и Ctrl+p для обычного терминала часто неразличимы.
        // Ваш parse_key_spec(int status, int32_t keycode) для Ctrl+буква
        // возвращает только Ctrl без Shift.
        //
        // Поэтому канонизируем так же:
        //
        // "Ctrl+P"       -> Ctrl + 'p'
        // "Ctrl+Shift+P" -> Ctrl + 'p'
        //
        // Если позже добавите Kitty keyboard protocol и захотите различать
        // Ctrl+Shift+p, тогда эту нормализацию нужно будет изменить.
        if (mods & ModifierKey::Ctrl)
        {
            mods = clear_shift(mods);
            return KeyEvent(static_cast<CharCode>(lower_cp), mods);
        }

        // Если пришла заглавная буква без Ctrl, считаем, что был Shift.
        //
        // "Q"       -> Shift + 'q'
        // "Shift+q" -> Shift + 'q'
        // "Shift+Q" -> Shift + 'q'
        if (cp != lower_cp)
        {
            mods |= ModifierKey::Shift;
        }

        return KeyEvent(static_cast<CharCode>(lower_cp), mods);
    }

    // Не буква: цифры, пунктуация, спецсимволы.
    //
    // Важно:
    // "Shift+1" в терминале обычно приходит как '!', а не как '1' + Shift.
    // Поэтому для пунктуации лучше биндить итоговый символ:
    //
    // "!"
    // "?"
    // "@"
    //
    // а не "Shift+1", "Shift+/", "Shift+2".
    return KeyEvent(static_cast<CharCode>(cp), mods);
}

} // namespace detail

inline KeyEvent parse_key_spec(std::string_view spec) noexcept
{
    spec = detail::trim(spec);

    if (spec.empty())
        return KeyEvent();

    // Разбиваем по '+'.
    //
    // Пример:
    //
    // "Ctrl+Shift+p"
    //
    // parts:
    // ["Ctrl", "Shift", "p"]
    //
    // Последние элементы считаются базовой клавишей,
    // все предыдущие — модификаторами.
    std::vector<std::string_view> parts;
    parts.reserve(4);

    std::size_t pos = 0;

    for (;;)
    {
        const std::size_t plus = spec.find('+', pos);

        if (plus == std::string_view::npos)
        {
            parts.push_back(detail::trim(spec.substr(pos)));
            break;
        }

        parts.push_back(detail::trim(spec.substr(pos, plus - pos)));
        pos = plus + 1;
    }

    if (parts.empty() || parts.back().empty())
        return KeyEvent();

    Modifiers mods = 0;

    // Все части, кроме последней — модификаторы.
    for (std::size_t i = 0; i + 1 < parts.size(); ++i)
    {
        const std::string m = detail::lower_ascii(parts[i]);

        if (m.empty())
            return KeyEvent();

        if (m == "ctrl" || m == "control" || m == "c")
        {
            mods |= ModifierKey::Ctrl;
        }
        else if (m == "shift" || m == "s")
        {
            mods |= ModifierKey::Shift;
        }
        else if (m == "alt" || m == "meta" || m == "m")
        {
            mods |= ModifierKey::Alt;
        }
        else
        {
            // Неизвестный модификатор.
            return KeyEvent();
        }
    }

    const std::string_view base = parts.back();

    // 1. Именованные клавиши: Up, Down, Enter, F5, Escape и т.п.
    if (auto named = detail::parse_named_key(base))
    {
        // Space в терминале обычно неотличим от Shift+Space.
        // Канонизируем так же, как runtime: просто Space.
        if (*named == NamedKey::Space)
        {
            mods = detail::clear_shift(mods);
        }

        return KeyEvent(*named, mods);
    }

    // 2. Клавиша '+'.
    //
    // Так как '+' у нас является разделителем, саму клавишу плюс
    // лучше задавать именем:
    //
    // "Plus"
    //
    // Можно также поддерживать экранирование, но для начала достаточно имени.
    if (detail::lower_ascii(base) == "plus")
    {
        return detail::make_char_key(U'+', mods);
    }

    // 3. Одиночный Unicode-символ, возможно UTF-8.
    const auto cp = detail::decode_utf8_char(base);

    if (!cp.has_value())
        return KeyEvent();

    return detail::make_char_key(*cp, mods);
}

} // namespace cui

#endif

}; // namespace cui