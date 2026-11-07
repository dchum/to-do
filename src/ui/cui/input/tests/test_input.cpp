#include <iostream>

#include "ncurses.h"
#include <cwchar>
#include <wchar.h>
#include "keyevent.h"
#include "input.h"

int main()
{
    setlocale(LC_ALL, "");

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Важно для Esc:
    // Сколько ncurses ждёт продолжение escape-последовательности.
    // Локально можно 25-50 мс, через SSH лучше 50-100 мс.
    set_escdelay(25);
    for ( ;; )
    {
        cui::KeyEvent key_spec = cui::readKeyEvent(  );

        std::cout << "key_spec = " << key_spec << std::endl;
    }
    // ваш цикл

    endwin();
    return 0;

}