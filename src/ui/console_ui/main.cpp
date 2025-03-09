#include <ncurses.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    initscr();
    printw("Русские буковки\n");
    getch();
    endwin();
    return 0;
}