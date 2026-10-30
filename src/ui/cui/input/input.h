#pragma once

#include "keyspec.h"

namespace cui {

/*! @brief Parses a key code into a key specification */
KeySpec parse_key_spec( int32_t keycode );

};