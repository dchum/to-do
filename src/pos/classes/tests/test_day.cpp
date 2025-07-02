#include <iostream>
#include <cassert>

#include "baseclass_day.h"

using namespace std;


void Test_Day()
{
    cout << ">>>>Testing class \"Day\"<<<<" << endl;
    {
        string name_1 = "Уборка в доме",
               name_2 = "Новая задача";

        STATUS status_1 = STATUS::SUCCES;

        Task task_1{name_1}, task_2{name_2};

        Day day;
        day.add_new_task(task_1);
        day.add_new_task(task_2);

        auto task_tmp_1 = day.get_task(task_1.name());
        auto task_tmp_2 = day.get_const_task(task_2.name());

        assert((*task_tmp_1).name() == task_1.name());
        assert((*task_tmp_2).name() == task_2.name());

        (*task_tmp_1).set_status(status_1);
        assert((*(day.get_task( task_1.name() ))).status() == status_1);

        for (auto tmp : day)
        {
            cout << tmp.name() << endl;
            assert(tmp.name() == task_1.name() || tmp.name() == task_2.name() );
        }

        assert(day.count_all_task()  == 2);
        assert(day.count_done_task() == 1);


        try
        {
            day.delete_task(task_1.name());
            day.delete_task(task_1.name());
        }
        catch(const std::runtime_error &e)
        {
            std::cerr << e.what() << '\n';
        }
        catch( const std::exception &e )
        {
            assert(false);
        }

    }
    cout << "**********Done!*************" << endl;
}