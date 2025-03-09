/******************************************************************************************************************************************
    Класс Окна - Window. Абстрактный класс. Описывает общие моменты касательно понятия
    окна, не относящиеся напрямую к UI.
     _______________________________________________
    |                                               |
    |                                               |
^   |                                               |h
|   |                                               |
|   |                                               |
|   |_______________________________________________|
|                           w
(0;0)------------->

    Поля класса:
    //NOTE -  v 1.0
[x]  w_, h_          : (int)                                -ширина высоты окна
[x]  xc_, yc_        : (int)                                -координаты нижней левой точки окна

    Методы класса:
    //NOTE -  v 1.0
[x]{x}  геттеры/сеттеры для всех полей класса

    update: (то есть возможно добавление в след версии)
*******************************************************************************************************************************************/
#pragma once
#include <string>

#include "global_lib.h"

namespace pos
{

class Window
{
    int w_,  h_,
        xc_, yc_;
        
    public:
        virtual ~Window() {}

        void set_size(Rect& new_size) //TODO - move-семантика
        {
            w_  = new_size.w_;
            h_  = new_size.h_;
            xc_ = new_size.xc_;
            yc_ = new_size.yc_;
        }
        
        Rect size( void ) const
        {   return Rect{.xc_ = xc_, .yc_ = yc_, .w_ = w_, .h_ = h_};    }

        Rect size( void ) 
        {   return Rect{.xc_ = xc_, .yc_ = yc_, .w_ = w_, .h_ = h_};    }

        virtual int draw( void ) = 0;

    protected:
        Window() = delete;

        explicit Window( Rect size = {0} )
          : w_(size.w_), h_(size.h_), xc_(size.xc_), yc_(size.yc_)
        {}
};

}