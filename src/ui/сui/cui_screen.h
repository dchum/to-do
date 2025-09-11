#pragma once

extern "C"
{
#include "cdkscreen.h"
#include "cdk_test.h"
}

#include <memory>
#include <vector>

#include "cui_widget.h"

namespace cui
{
    class ScreenIter: public Iterator<Widget>
    {
        std::vector<Widget*>& vector_;
        std::vector<Widget*>::iterator current;

    public:
        ScreenIter(std::vector<Widget*>& v)
            :Iterator(),
            vector_(v), current(v.begin())
        {}

        void Begin() override 
        {
            current = vector_.begin();
        }

        void Next() override 
        {
            ++current;
        }

        bool IsDone() const override
        {
            return current == vector_.end();
        }

        Widget& CurrentValue() const override
        {
            return *(*current);
        }
        
        ~ScreenIter(){}
    };
    

    class CUIScreen final : public Widget
    {
    private:
        CDKSCREEN * screen_;
        std::vector<Widget*> children_;
        
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
        void draw   ( void ) override;
        void hide   ( void ) override;
        void refresh( void );

        // void activate ( unsigned int* ) override {}

        // void add_child( Widget* child ) override;
        // it_wdgt children( void )  override;
        
        // Widget* screen ( void ) override;

    };

}