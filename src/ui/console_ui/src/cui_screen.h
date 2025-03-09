#pragma once

extern "C"
{
#include "cdkscreen.h"
#include "cdk_test.h"
}

#include <memory>

namespace cui
{

class CUIScreen
{

private:
    CDKSCREEN * screen_;

public:
    CUIScreen()
    :screen_( initCDKScreen (NULL) ) {   initCDKColor ();    }

    ~CUIScreen()
    { 
        destroyCDKScreen(screen_);
        endCDK();
        ExitProgram (EXIT_SUCCESS);
    }

    CUIScreen& operator=( const CUIScreen& ) = delete;
    CUIScreen( const CUIScreen& ) = delete;

    CDKSCREEN* get(void){   return screen_;  }
};

}