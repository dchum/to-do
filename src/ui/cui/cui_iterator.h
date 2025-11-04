#pragma once

#include <stdexcept>
#include <memory>


namespace cui 
{   
    class Widget;

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

    using NULLIterWdgt = NullIterator<Widget>;
    using IterWdgt     = std::unique_ptr<Iterator<Widget>>;
    using PtrIterWdgt  = Iterator<Widget>;

    inline const NULLIterWdgt NullIterOBJ{};

} // namespace cui