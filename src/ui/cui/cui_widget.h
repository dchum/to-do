/******************************************************************************************************************************************
Класс Окна - Widget. Абстрактный класс. Описывает общие моменты касательно понятия "Виджет"

    Поля класса:
    //NOTE -  v 1.0

    Методы класса:
    //NOTE -  v 1.0

    update: (то есть возможно добавление в след версии)
*******************************************************************************************************************************************/
#pragma once

#include <memory>

#include "cui_lib.h"
#include "cui_screen.h"
#include "cui_iterator.h"
#include "cui_surface.h"

//FIXME - упорядочить функции: какие просто наследуем, какие обязательно переопределяем
namespace cui
{   

class Widget
{
    static inline ssize_t new_id;
    const ssize_t id_;
    
    std::unique_ptr<Surface> surface_imp_;
    
protected:
    CUIScreen& screen_;
    Size size_; //< размеры пространства доступные для отрисовки, физически реальные размеры

protected:
    Widget( CUIScreen& screen, std::unique_ptr<Surface> surface_imp );

public:
    virtual ~Widget();

public:
    int x0( void );
    int y0( void );
    virtual int  width ( void ) const noexcept;
    virtual int  height( void ) const noexcept;
    virtual void draw  ( void ) = 0;
    virtual void hide  ( void ) = 0;
    virtual char* handle( uint* ) { return nullptr; }
    virtual void move( Alignment, Alignment ) {}

public:
    ssize_t get_id( void ) const noexcept;

    CUIScreen& get_screen() { return screen_; }
};//class Widget


inline bool operator == (const Widget& lhs, const Widget& rhs)
{
    return lhs.get_id() == rhs.get_id();
}

inline bool operator < (const Widget& lhs, const Widget& rhs)
{
    return lhs.get_id() < rhs.get_id();
}

} // namespace cui