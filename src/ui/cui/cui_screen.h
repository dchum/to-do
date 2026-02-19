#pragma once

extern "C"
{
#include "cdkscreen.h"
#include "cdk_test.h"
}

#include <memory>
#include <list>


namespace cui
{ 

class CUIScreen final
{
private:
    std::unique_ptr<CDKSCREEN> screen_;
    
public:
    CUIScreen( void );
    ~CUIScreen();

    CUIScreen( const CUIScreen& ) = delete;
    CUIScreen& operator=( const CUIScreen& ) = delete;

    CDKSCREEN* get(void){   return screen_.get();  }

    int width(void) const noexcept;
    int height(void) const noexcept;
};

}