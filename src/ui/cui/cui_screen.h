#pragma once

extern "C"
{
#include "cdkscreen.h"
#include "cdk_test.h"
}

#include <memory>
#include <list>

#include "cui_widget.h"

namespace cui
{ 

    class CUIScreen final : public Widget
    {
    private:
        CDKSCREEN * screen_;
        std::list<Widget*> children_;
        
    public:
        CUIScreen( void );
        ~CUIScreen();

        CUIScreen( const CUIScreen& ) = delete;
        CUIScreen& operator=( const CUIScreen& ) = delete;

        CDKSCREEN* get(void){   return screen_;  }

    public:
        IterWdgt CreateIterator( void ) override;
        CDKSCREEN * screen()            override;

        void OnAddChild   (Widget* child) override;
        void OnRemoveChild(Widget* child) override;

    public:
        int  width  ( void ) const noexcept;
        int  height ( void ) const noexcept;
        void draw   ( void ) override;
        void hide   ( void ) override;
        void refresh( void );

        // void activate ( unsigned int* ) override {}

        // void add_child( Widget* child ) override;
        // it_wdgt children( void )  override;
        
        // Widget* screen ( void ) override;

    };

}