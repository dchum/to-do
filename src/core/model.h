#pragma once

#include "common/module.h"
#include "common/commands.h"
#include "common/events.h"


namespace core
{

class Model final : public common::Module
{
    WorkSpace board_;

public:
    void CreateWorkSpace( const std::string& work_space_name );
    

    void update ( CommandMessage cmd );

};//class Model

}//namespace core