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
#include <tuple>

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
        Widget*  parent_;

        static inline ssize_t new_id;
        const ssize_t id_;

        struct size_widget_t
        {
            int width_, height_; //Размеры предоставленного места на терминале,
                                 //лишь у CDKSCREEN будет равно размеру всего терминала
            int percent_of_width_, 
                percent_of_height_;

                size_widget_t()=default;
        }size;

        void SetParentInternal( Widget* new_parent);

    protected:
        virtual void OnAddChild   (Widget* child);
        virtual void OnRemoveChild(Widget* child);

    protected:
        template <typename Iter, typename... Args>
        IterWdgt create_iterator(Args&&... args);
        explicit Widget(Widget* parent);

    public:
        Widget(const Widget& ) = delete;
        Widget(const Widget&&) = delete;
        Widget& operator=(const Widget& ) = delete;
        Widget& operator=(const Widget&&) = delete;
        virtual ~Widget();

    public:
        virtual IterWdgt CreateIterator( void );

        template<typename T, typename... Args>
        void AddChild     ( Args&&... args     );
        void AddChild     ( Widget* child      );
        void RemoveChild  ( Widget* child      );
        void SetParent    ( Widget* new_parent );
        void RemoveParent ( void );
        Widget* getParent ( void );
    
        virtual CDKSCREEN * screen();

    public:
        int  width ( void ) const noexcept;
        int  height( void ) const noexcept;
        void set_size( int w_percent,  int h_percent ) noexcept;
        void set_internal_size( int w, int h ) noexcept;
        std::tuple<int, int> get_size( void ) const noexcept;
        virtual void draw  ( void ) = 0;
        virtual void hide  ( void ) = 0;
        // virtual void update( void ) = 0;

    public:
        ssize_t get_id( void ) const noexcept;
    };

    template <typename Iter, typename... Args>
    inline IterWdgt Widget::create_iterator(Args&&... args)
    {
        return std::make_unique<Iter>( std::forward<Args>(args)... );
    }

    template <typename T, typename... Args>
    inline void Widget::AddChild(Args &&...args)
    {
        Widget* wdgt = new T(this, std::forward<Args>(args)...);
        this->AddChild(wdgt);
    }

    inline bool operator == (const Widget& lhs, const Widget& rhs)
    {
        return lhs.get_id() == rhs.get_id();
    }

    inline bool operator < (const Widget& lhs, const Widget& rhs)
    {
        return lhs.get_id() < rhs.get_id();
    }

} // namespace cui