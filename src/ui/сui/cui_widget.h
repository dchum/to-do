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
        virtual IterWidgets* CreateIterator( void );
        virtual void AddChild( Widget* other );
        virtual CDKSCREEN * screen();

    public:
        virtual int  width ( void ) = 0;
        virtual int  height( void ) = 0;
        virtual void draw  ( void ) = 0;
        virtual void hide  ( void ) = 0;
    };

    // using PtrWidget = std::unique_ptr<Widget>;

    template <typename Iter, typename... Args>
    inline Iter* Widget::create_iterator(Args&&... args)
    {
        if ( iter_ != nullptr )
            delete iter_;

        iter_ = new Iter(std::forward<Args>(args)...);

        return static_cast<Iter*>(iter_);
    }

} // namespace cui