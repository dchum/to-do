/******************************************************************************************************************************************
    Класс Окна - Window. Абстрактный класс. Описывает общие моменты касательно понятия
    окна, не относящиеся напрямую к UI.
     _______________________________________________
    |подзалоговок1     ЗАГОЛОВОК       подзалоговок1| <- шапка окна (шапка может отсут)
    |-----------------------------------------------|
^   |                                               |h
|   |                    ТЕКСТ                      |
|   |                                               |
|   |служебная инф._________________________________|
|                           w
(0;0)------------->

    Поля класса:
    //NOTE -  v 1.0

    Методы класса:
    //NOTE -  v 1.0
[x]{x}   

    update: (то есть возможно добавление в след версии)
*******************************************************************************************************************************************/
#pragma once
#include <string>

namespace pos
{
class Window
{
    bool is_has_header_;
    
    std::string header_,
                subtitle_left_,
                subtitle_right_;
    int w,  h,
        xc, yc;
        
    public:
        virtual ~Window() = 0;

        void set_header(std::string new_header)//TODO - move-семантика
        { header_ = new_header; }
        const std::string& header( void ) const
        {   return header_;    }
        std::string& header( void )
        {   return const_cast<std::string&> (static_cast<const Window&> (*this).header()) ;    }

        
        
    protected:
        Window()
        : is_has_header_(false), header_(),
            subtitle_left_(), subtitle_right_(),
            w(0), h(0), xc(0), yc(0)
        {}
};
}