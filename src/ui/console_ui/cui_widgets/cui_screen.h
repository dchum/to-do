#pragma once

extern "C"
{
#include "cdkscreen.h"
#include "cdk_test.h"
}

#include <memory>

#include "list"
#include "cui_widget.h"

namespace cui
{

class CUIScreen final : public Widget
{
private:
    CDKSCREEN * screen_;
    list_wdgt children_;

    int width_, height_;
    
public:
    CUIScreen( void );
    ~CUIScreen();

    CUIScreen( const CUIScreen& ) = delete;
    CUIScreen& operator=( const CUIScreen& ) = delete;

    CDKSCREEN* get(void){   return screen_;  }

    void refresh(void);

    void draw ( void ) override;
    void hide ( void ) override;
    void activate ( unsigned int* ) override {}

    void add_child( Widget* child ) override;
    it_wdgt children( void )  override;
    
    Widget* screen ( void ) override;

    int width () override;
    int height() override;
};

}