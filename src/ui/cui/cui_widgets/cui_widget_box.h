#pragma once

#include <memory>
#include <list>

#include "cui_widget.h"
#include "cui_screen.h"

#include "cdk/binding.h"
#include "cdk/curdefs.h"
#include "cdk/cdk_objs.h"
#include "cdk/cdkscreen.h"


namespace cui
{
    class widgetBox_impl_;

    class CUIBorder;
    class WidgetBox : public Widget
    {
        std::list<Widget*> childrens_;
        widgetBox_impl_ * impl_;

        CUIBorder* bord_;//FIXME - использовать умный указатель

        void OnAddChild   (Widget* child) override;
        void OnRemoveChild(Widget* child) override;

    public:
        WidgetBox(Widget* parent);
        WidgetBox(Widget* parent, int x, int y, int width, int height);
        
        ~WidgetBox();

        void ShowBorder( bool is_show );
        void ShowBorder( bool top, bool left, bool right, bool bottom );

        void draw  ( void ) override;
        void hide  ( void ) override;
        
        IterWdgt CreateIterator( void ) override;
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
