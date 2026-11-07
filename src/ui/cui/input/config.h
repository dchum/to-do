#pragma once

#include <string_view>
#include <map>

#include "commands.h"
#include "keyevent.h"

namespace cui
{

class ConfigStorage
{    
    std::string configFile;
    std::map<common::CommandId, KeyEvent> storage;

public:
    ConfigStorage( std::string_view configFile ) noexcept;

    void readConfig( void );

    auto begin() noexcept {  return storage.begin(); }
    auto end()   noexcept {  return storage.end();   }

    auto cbegin() const noexcept {  return storage.cbegin(); }
    auto cend()   const noexcept {  return storage.cend();   }
};

}//namespace cui