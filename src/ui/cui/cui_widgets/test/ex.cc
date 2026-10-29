#include <iostream>

#define _XOPEN_SOURCE_EXTENDED
#include "ncurses.h"
#include <cwchar>

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
    // set_escdelay(25);
    for ( ;; )
    {
        wint_t wc;
        int rc = get_wch(&wc);
        std::cout << "rc=" << rc << " wc=" << std::hex << wc << std::dec << " wc=" << wc << std::endl;
    }
    // ваш цикл

    endwin();
    return 0;

}