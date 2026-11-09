#pragma once

#include <string_view>

#include "keyevent.h"

namespace cui {

KeyEvent readKeyEvent( void );

KeyEvent parse_key_spec( std::string_view keySpec );

};