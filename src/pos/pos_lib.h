#pragma once
/*****************************************************************************************************************************
POS - пользовательская операционная система. Пафосное название, не более.
Раздел в проекте, хранящий общую информацию касающуюся всех остальных
разделом и обменов между ними. В отличие от библиотеки lib описывает конкретные
понятия.
****************************************************************************************************************************** */
#include <vector>
#include <memory>

#include "lib.h"

namespace pos
{
// using ptr_frame  = std::shared_ptr<Frame>;

// enum class FRAME_KANBAB
// {

// };

// class Frame 
// {
// private:
//     FRAME_KANBAB frame_;

//     std::vector<ptr_bclass> base_classes;
// public:
//     Frame(FRAME_KANBAB frame);
//     Frame(const Frame&) = delete;
//     Frame& operator=(const Frame&) = delete;

//     ~Frame() = default;

//     void add_bclass(ptr_bclass bclass);
// };

// class Kanban
// {
// private:
//     std::vector<ptr_bclass> base_classes;

//     STATUS init( void );
// public:
//     Kanban();
//     ~Kanban() = default;

//     Kanban (const Kanban&) = delete;
//     Kanban& operator= (Kanban& ) = delete;
// };


}

