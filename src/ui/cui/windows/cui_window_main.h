#pragma once

#include <map>
#include <memory>

#include "cui_window.h"

namespace cui
{

class WindowMain final: public Window
{
    void init_bindigs_keys( void );

public:
    WindowMain( CUIScreen& screen );

    void init() override;

    std::optional<CommandMessage> update( int key ) override;
};

}