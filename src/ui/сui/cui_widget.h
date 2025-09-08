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

extern "C"
{
#include "cdkscreen.h"
// #include "cdk_test.h"
}

#include "cui_iterator.h"

namespace cui
{   

    class Widget
    {
        Widget*      parent_;
        IterWidgets* iter_;

    protected:
        template <typename Iter, typename... Args>
        Iter* create_iterator(Args&&... args);

    public:
        explicit Widget(Widget* parent);
        Widget(const Widget& ) = delete;
        Widget(const Widget&&) = delete;
        Widget& operator=(const Widget& ) = delete;
        Widget& operator=(const Widget&&) = delete;
        virtual ~Widget();

    public:
        virtual IterWdgt CreateIterator( void );
        virtual CDKSCREEN * screen();

    public:
        virtual int  width ( void ) { return 0; };
        virtual int  height( void ) { return 0; };
        virtual void draw  ( void ) = 0;
        virtual void hide  ( void ) = 0;
    };

    template <typename Iter, typename... Args>
    inline IterWdgt Widget::create_iterator(Args&&... args)
    {
        return std::make_unique<Iter>( std::forward<Args>(args)... );
    }

        iter_ = new Iter(std::forward<Args>(args)...);

        return static_cast<Iter*>(iter_);
    }

} // namespace cui