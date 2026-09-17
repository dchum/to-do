#include "model_column.h"

#include <algorithm>
#include <numeric>

#include <ptrcheck.h>

namespace core
{
ColumnID Column::id = 0;

    Column::Column(std::string name)
    :id_(id++), name_level_(name)
{
}

void Column::AttachTask( TaskID task_id )
{
    tasks_id_.push_back( task_id );
}

void Column::DetachTask( TaskID task_id )
{
    auto it = std::remove_if(tasks_id_.begin(), tasks_id_.end(),
                             [task_id](const TaskID id) { return id == task_id; });

    if ( it != tasks_id_.end() )                         
        tasks_id_.erase(it, tasks_id_.end());
}


}//namespace core