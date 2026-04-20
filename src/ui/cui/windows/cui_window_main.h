#pragma once

#include <map>
#include <memory>

#include "cui_window.h"

namespace cui
{

class WindowMain final: public Window
{
    // std::map<int, std::unique_ptr<Command> > bindings_;

    // cui::Command& get_command_binding(unsigned int key) override;
    
    void init_bindigs_keys( void );

public:
    WindowMain( CUIScreen& screen );

    void init() override;

    std::optional<CommandMessage> update( int key ) override;
};

}