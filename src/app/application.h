#pragma once

#include <queue>

#include "ui.h"
#include "model.h"

#include "commandmessage.h"

namespace app{

class Application
{
    bool is_running_ = true;
    unsigned int input_;

    ui::Ui      ui_core_;
    core::Model model_core_;

    std::queue<CommandMessage> queue_ui2core;

public:
    void init( );
    void exec( );
};


}