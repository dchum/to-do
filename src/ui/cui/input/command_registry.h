#pragma once 

#include <map>
#include <concepts>

#include "commands.h"
#include "keyevent.h"


template<typename T>
concept BindingIterator = requires(T t) 
{
    { t->first } -> std::same_as<const cui::KeyEvent&>;
    { t->second } -> std::same_as<common::CommandId&>;
};


namespace cui {

class CommandRegistry {

private:
    std::map< KeyEvent, common::CommandId > storage;

    void bind(KeyEvent key, common::CommandId cmd) 
    {
        storage[key] = cmd;
    }

public:

    template<BindingIterator Iter>
    void registerBindings(Iter begin, Iter end)
    {
        for (auto it = begin; it != end; ++it) 
        {
            bind(it->first, it->second);
        }
    }

    bool hasBinding(KeyEvent key) const noexcept 
    {
        return storage.contains(key);
    }

    common::CommandId getCommand(KeyEvent key) const 
    {
        return storage.at(key);
    }
};

} // namespace cui