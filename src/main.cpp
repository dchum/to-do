#include <iostream>

#include "pos_lib.h"
#include "ui_main.h"


int main()
{
    // pos_main(); //< инициализация кадров из pos_main.h

    ui_main();  //< инициализация UI из ui_main.h, отдельный поток

    return 0;
}