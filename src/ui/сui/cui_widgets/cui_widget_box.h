#pragma once

#include <memory>
#include <vector>

#include "cui_widget.h"
#include "cui_screen.h"

#include "cdk/binding.h"
#include "cdk/curdefs.h"
#include "cdk/cdk_objs.h"
#include "cdk/cdkscreen.h"


namespace cui
{
    class VectorIterator : public IterWidgets
    {
        std::vector<Widget*>& vector_;
        std::vector<Widget*>::iterator current_;
        
    public:
        VectorIterator( std::vector<Widget*>& v ) 
        :IterWidgets(),
         vector_(v), current_(v.begin())
        {

        }
        void Begin() override {
            current_ = vector_.begin();
        }
        void Next()  override {
            ++current_;
        }
        bool IsDone() const override {
            return current_==vector_.end();
        }
        Widget& CurrentValue() const override {
            return *(*current_);
        }
    };
    
    class WidgetBox : public Widget
    {
        int width_, height_;
        std::vector<Widget*> childrens_;

    public:
        WidgetBox(Widget* parent);
        ~WidgetBox();

        int  width ( void ) override;
        int  height( void ) override;
        void draw  ( void ) override;
        void hide  ( void ) override;

        IterWidgets* CreateIterator( void ) override;
        void AddChild( Widget* other ) override;
    };
    //     private:
    //         list_wdgt children_;
    //         CUIScreen* screen_;

    //     it_wdgt activ_widget_; //< по умолчанию активным будет первый виджет

    //     void correct_activ_widget( void );

    //     int key_input( void ); //< вовзращает признак дальнейшего продолжения программы
        
    //     void set_next_widget( void );
        
    //     void add_child( Widget* child ) override;

    //     bool is_run_;
    //     unsigned int key_;


    // public:
    //     WidgetBox( Widget* parent );
    //     ~WidgetBox();

    //     WidgetBox( const WidgetBox& ) = delete;

    //     WidgetBox& operator=( const WidgetBox& ) = delete;

    //     it_wdgt children( void ) override;
    //     Widget*   screen( void )   override;

    //     void activate( unsigned int* ) override;

    //     void end( void ); //NOTE - нужна ли такая функция???

}//namespace cui
