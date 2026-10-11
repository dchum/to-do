#pragma once

#include <vector>
#include <functional>
#include <map>

#include "common/module.h"
#include "common/module_id.h"

namespace app
{

class Router
{
    std::vector<std::reference_wrapper<common::Module>> modules_;
    std::map<common::ModuleId, std::vector<std::reference_wrapper<common::Module>>> subscriptions_;

public:
    void AddModule( common::Module & md );

    void update( void );
};//class Router

    
}