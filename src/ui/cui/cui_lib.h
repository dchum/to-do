#pragma once

#include <string>
#include <vector>

extern "C"
{
    #include "cdk.h"
}

namespace cui
{

enum class Alignment
{
    Left	   = LEFT,
    Right	   = RIGHT,
    Center	   = CENTER,
    // Top	       = TOP,
    // Bottom	   = BOTTOM,
    // Horizontal = HORIZONTAL,
    // Vertical   = VERTICAL,
    // Full	   = FULL,
};


class Message
{
    std::vector< std::string > strings_;

public:
    Message() = delete;
    Message(const std::string& str); //сам разобьет на массив и посчитает кол-во строк
    
    ~Message() {};

    const std::vector< std::string >& tokens ( void )const noexcept { return strings_; };

    int count( void ) const noexcept {    return strings_.size();    };
    int count( void ) noexcept       {    return strings_.size();    };
};

class CStringArray {
    std::vector<char*> pointers;

public:
    explicit CStringArray(const Message& );
    
    ~CStringArray(){
        for ( auto& p : pointers )
            delete[] p;
    }

    char** data() { return pointers.data(); }

    size_t size() const { return pointers.size(); }
};

}
