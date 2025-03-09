#pragma once

#include <string>


const char CHAR_SEPARATOR = '|';


namespace cui
{

class Message
{
    char** ptr_str_;
    int count_;

public:
    Message() = delete;
    Message(std::string& str); //сам разобьет на массив и посчитает кол-во строк

    ~Message();

    char** get( void ) {   return ptr_str_;   }

    int count( void ) const noexcept {    return count_;    };
    int count( void ) noexcept       {    return count_;    };
};

}