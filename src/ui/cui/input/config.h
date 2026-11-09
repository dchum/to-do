#pragma once

#include <string_view>
#include <map>
#include <vector>

#include "commands.h"
#include "keyevent.h"

namespace cui
{

class ConfigStorage
{    
    std::string configFile;
    std::map< common::CommandId, std::vector<KeyEvent> > bindings_map;

public:
    ConfigStorage( std::string_view configFile ) noexcept;

    void readConfig( void );

    auto begin() noexcept {  return bindings_map.begin(); }
    auto end()   noexcept {  return bindings_map.end();   }

    auto cbegin() const noexcept {  return bindings_map.cbegin(); }
    auto cend()   const noexcept {  return bindings_map.cend();   }
};

}//namespace cui