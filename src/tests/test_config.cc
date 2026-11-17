#include <iostream>

#include <stdexcept>

#include "keyevent.h"
#include "key_input.h"
#include "config.h"

int main() try
{
    using namespace cui;

    ConfigStorage cnfg{"bindKeys.json"};

    cnfg.readConfig();

#if 0

    for ( auto&& bind : cnfg )
    {
        std::cout << bind.first << ": ";
        for ( const auto& key : bind.second )
        {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }
    
    CommandRegistry cmdreg;

    cmdreg.registerBindings( cnfg.begin(), cnfg.end() );

    for ( ; ; )
    {
        KeyEvent kevent = readKeyEvent();

        if ( cmdreg.hasBinding( kevent ) )
        {
            std << kevent << "->" << cmdreg.getCommand( kevent );
        }
        else
        {
            std::cerr << kevent << " not found in config-file" << std::endl;
        }
    }
#endif
}
catch ( std::exception& e)
{
    std::cerr << e.what() << std::endl;
}