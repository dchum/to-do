#pragma once

#include <vector>
#include <optional>

#include "model_service.h"

#include "commandmessage.h"


namespace core
{

class Model
{
    WorkSpace board_;

public:
    void CreateWorkSpace( const std::string& work_space_name );
    

    void update ( CommandMessage cmd );

};//class Model

}//namespace core