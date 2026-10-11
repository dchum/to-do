#pragma once

#include "common/module.h"
#include "common/commands.h"
#include "common/events.h"

#include "cui/cui_main.h"

namespace ui
{

class Ui final : public common::Module {
    cui::CUICore cui_core_;

public:
    void update( void ) const;

};//class Ui

}//namespace ui
