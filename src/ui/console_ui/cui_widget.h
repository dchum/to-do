/******************************************************************************************************************************************
    Класс Окна - Widget. Абстрактный класс. Описывает общие моменты касательно понятия "Виджет"

    Поля класса:
    //NOTE -  v 1.0

    Методы класса:
    //NOTE -  v 1.0

    update: (то есть возможно добавление в след версии)
*******************************************************************************************************************************************/
#pragma once
#include <string>
#include <memory>
#include <list>


namespace cui
{
class Widget;

using c_it_wdgt = std::list<Widget*>::const_iterator;
using it_wdgt   = std::list<Widget*>::iterator;

using list_wdgt = std::list<Widget*>;

class Widget
{
private:
    const Widget* parent_;

    virtual void add_child ( Widget* child ) { if ( child ) return; } ;
public:
    explicit Widget(Widget* parent);

    Widget(const Widget&) = delete;
    Widget& operator=(const Widget*) = delete;

    virtual ~Widget(){}

    const Widget&   parent( void );

    virtual c_it_wdgt children( void ) { return c_it_wdgt(nullptr); };
    virtual Widget*   screen( void )   { return nullptr; };

    bool active_; //< можно ли взаимодействовать с виджетом или он сам по себе

    virtual int width ( void ) = 0;
    virtual int height( void ) = 0;

    virtual void draw    ( void ) = 0;
    virtual void hide    ( void ) = 0;
    virtual void activate( unsigned int* ) = 0;
};

}