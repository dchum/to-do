#pragma once

#include <queue>

#include "ui/ui.h"
#include "core/model.h"
#include "router.h"

namespace app{

class Application
{
    Router router_;
    
    bool is_running_ = true;

    ui::Ui      ui_core_;
    core::Model model_core_;


public:
    void init( );
    void exec( );
};


}