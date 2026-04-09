#pragma once

#include "ui.h"
#include "model.h"

namespace app{

class Application
{
    bool is_running_ = true;
    unsigned int input_;

    ui::Ui      ui_core_;
    core::Model model_core_;

public:
    void init( ) {}
    void exec( );
};


}