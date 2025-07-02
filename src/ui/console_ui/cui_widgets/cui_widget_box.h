#pragma once

#include <memory>

#include "cui_widget.h"
#include "cui_screen.h"

#include "cdk/binding.h"
#include "cdk/curdefs.h"
#include "cdk/cdk_objs.h"
#include "cdk/cdkscreen.h"


namespace cui
{

class WidgetBox : public Widget
{
private:
    list_wdgt children_;
    CUIScreen* screen_;

    it_wdgt activ_widget_; //< по умолчанию активным будет первый виджет

    void correct_activ_widget( void );

    int key_input( void ); //< вовзращает признак дальнейшего продолжения программы
    
    void set_next_widget( void );
    
    void add_child( Widget* child ) override;

    bool is_run_;
    unsigned int key_;

    int width_, 
        height_;

public:
    WidgetBox( Widget* parent );
    ~WidgetBox();

    WidgetBox( const WidgetBox& ) = delete;

    WidgetBox& operator=( const WidgetBox& ) = delete;

    it_wdgt children( void ) override;
    Widget*   screen( void )   override;

    int width ( void ) override;
    int height( void ) override;

    void draw    ( void ) override;
    void hide    ( void ) override;
    void activate( unsigned int* ) override;

//     void end( void ); //NOTE - нужна ли такая функция???
};

}
