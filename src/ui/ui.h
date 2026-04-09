#pragma once

#include "cui/cui_main.h"

namespace ui
{

class Ui{
    cui::CUICore cui_core_;

public:
    CommandMessage HandleInput( );
};//class Ui

}//namespace ui
