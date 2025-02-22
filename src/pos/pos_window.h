/******************************************************************************************************************************************
    Класс Окна - Window. Абстрактный класс. Описывает общие моменты касательно понятия
    окна, не относящиеся напрямую к UI.
     _______________________________________________
    |подзалоговок1     ЗАГОЛОВОК       подзалоговок2| <- шапка окна (шапка может отсут)
    |-----------------------------------------------|
^   |                                               |h
|   |                    ТЕКСТ                      |
|   |                                               |
|   |служебная инф._________________________________|
|                           w
(0;0)------------->

    Поля класса:
    //NOTE -  v 1.0
[x]  w_, h_          : (int)                                -ширина высоты окна
[x]  xc_, yc_        : (int)                                -координаты нижней левой точки окна
[x]  header_         : (string)                             -ЗАГОЛОВОК
[x]  subtitle_left_  : (string)                             -подзаголовок1
[x]  subtitle_right_ : (string)                             -подзалоговок2
[x]  is_has_header_  : (bool)                               -признак наличия шапка у окна

    Методы класса:
    //NOTE -  v 1.0
[x]{x}  геттеры/сеттеры для всех полей класса

    update: (то есть возможно добавление в след версии)
*******************************************************************************************************************************************/
#pragma once
#include <string>

#include <global_lib.h>

namespace pos
{

class Window
{
    bool is_has_header_;
    
    std::string header_,
                subtitle_left_,
                subtitle_right_;
    int w_,  h_,
        xc_, yc_;
        
    public:
        virtual ~Window() = 0;

        void set_header(std::string new_header)//TODO - move-семантика
        {   header_ = new_header;   is_has_header_ = true;    }

        const std::string& header( void ) const
        {   return header_;    }

        std::string& header( void )
        {   return const_cast<std::string&> (static_cast<const Window&> (*this).header()) ;    }


        void set_subtitle_left(std::string new_subtitle_left_)//TODO - move-семантика
        {   subtitle_left_ = new_subtitle_left_;    is_has_header_ = true;   }

        const std::string& subtitle_left( void ) const
        {   return subtitle_left_;    }

        std::string& subtitle_left( void )
        {   return const_cast<std::string&> (static_cast<const Window&> (*this).subtitle_left()) ;    }


        void set_subtitle_right(std::string new_subtitle_right)//TODO - move-семантика
        {   subtitle_left_ = new_subtitle_right;    is_has_header_ = true;   }

        const std::string& subtitle_right( void ) const
        {   return subtitle_left_;    }

        std::string& subtitle_right( void )
        {   return const_cast<std::string&> (static_cast<const Window&> (*this).subtitle_right()) ;    }


        Rect set_size(Rect& new_size) //TODO - move-семантика
        {
            w_  = new_size.w_;
            h_  = new_size.h_;
            xc_ = new_size.xc_;
            yc_ = new_size.yc_;
        }
        
        Rect size( void ) const
        {   return Rect{.w_ = w_, .h_ = h_, .xc_ = xc_, .yc_ = yc_};    }

        Rect size( void ) 
        {   return Rect{.w_ = w_, .h_ = h_, .xc_ = xc_, .yc_ = yc_};    }

        
        void set_header(bool is_has_header)
        {   is_has_header_ = is_has_header;    }

        bool is_has_header( void ) const
        {   return is_has_header_;    }

        bool is_has_header( void )
        {   return is_has_header_;    }

    protected:
        Window() = delete;

        Window(Rect size = {0}, bool has_header = false, std::string header = "", std::string subtitle_left = "",
               std::string subtitle_right_ = "")
        : is_has_header_(has_header),    header_(header),
          subtitle_left_(subtitle_left), subtitle_right_(subtitle_right_),
          w_(size.w_), h_(size.h_), xc_(size.xc_), yc_(size.yc_)
        {}
};

}