#pragma once

#include <iterator>
#include <stdexcept>


namespace cui 
{   

    template <typename T>
    class Iterator
    {
    public:
        constexpr Iterator(){};

        virtual void Begin () = 0;
        virtual void Next  () = 0;
        virtual bool IsDone()     const = 0;
        virtual T& CurrentValue() const = 0;

        virtual ~Iterator() {};
    };

    

    template <typename T>
    class NullIterator : public Iterator<T>
    {
    public:
        constexpr NullIterator(){};

        void Begin ()  override { };
        void Next  ()  override { };
        bool IsDone()  const override { return true; };
        T& CurrentValue() const override 
        { 
            throw std::runtime_error("NullIterator -> Invalid operation!\n") ;
        };
    };

    class Widget;
    using NullIterWidgets = NullIterator<Widget>;
    using IterWidgets = Iterator<Widget>;

    inline const NullIterWidgets NullIterOBJ{};

} // namespace cui