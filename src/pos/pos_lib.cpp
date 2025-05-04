#include "pos_lib.h"

#include <algorithm>
#include <memory>

// #include "baseclass_board.h"
#include "baseclass_task.h"

namespace pos
{

// pos::Frame::Frame(FRAME_KANBAB frame)
//     :frame_(frame)
// { }

// void Frame::add_bclass(ptr_bclass bclass)
// {
//     base_classes.push_back(bclass);
// }



Kanban::Kanban()
{
    init();
}


STATUS Kanban::init(void)
{
    base_classes.push_back(std::make_shared<pos::Task>("task#1"));
    base_classes.push_back(std::make_shared<pos::Task>("task#2"));
    base_classes.push_back(std::make_shared<pos::Task>("task#3"));

    return STATUS::SUCCES;
}



}
