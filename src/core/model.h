#pragma once

#include <vector>
#include <optional>

#include "model_service.h"


namespace core
{

class Model
{
    Board board_;

public:
    void update ( CommandMessage cmd );

};//class Model

}//namespace core