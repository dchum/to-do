#pragma once

#include <string>


namespace cui
{

class Message
{
    char** ptr_str_;
    int count_;

public:
    Message() = delete;
    Message(const std::string& str); //сам разобьет на массив и посчитает кол-во строк
    
    Message& operator=(const Message&) = delete;

    ~Message();

    char** get_msg( void ) {   return ptr_str_;   }

    int count( void ) const noexcept {    return count_;    };
    int count( void ) noexcept       {    return count_;    };
};

}