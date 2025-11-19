#pragma once

#include <list>

#include "cui_iterator.h"
#include "cui_widget.h"

namespace cui
{
    class ListIterator : public Iterator<Widget>
    {
        std::list<Widget*>& list_;
        std::list<Widget*>::iterator current_;
        
    public:
        ListIterator( std::list<Widget*>& l ) 
        :Iterator(),
         list_(l), current_(l.begin())
        {

        }
        void Begin() override {
            current_ = list_.begin();
        }
        void Next()  override {
            ++current_;
        }
        bool IsDone() const override {
            return current_==list_.end();
        }
        Widget& CurrentValue() const override {
            return *(*current_);
        }
    };
}