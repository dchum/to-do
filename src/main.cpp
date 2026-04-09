#include <iostream>

#include "app/application.h"


int main()
{
    app::Application app;

    app.init();

    app.exec();

    return 0;
}