#include <iostream>
#include <cassert>

#include "baseclass_task.h"

using namespace std;

void Test_Task()
{
    cout << ">>>>Testing class \"Task\"<<<<" << endl;
    {
        string name = "Уборка в доме",
            description = "какое-то описание задачи";

        STATUS status = STATUS::FAIL;

        Task task{name};
        task.set_description(description);
        task.set_status(status);

        assert(task.name() == name);
        assert(task.description() == description);
        assert(task.status() == status);

        name = "Новая задача";
        task.set_name(name);
        assert(task.name() == name);
    }
    cout << "**********Done!*************" << endl;
}