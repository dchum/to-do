#include "cui_lib.h"


#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

#include <iostream>

cui::Message::Message(std::string &str)
    :ptr_str_(nullptr), count_(0)
{
    std::string::iterator it_prev = str.begin();
    std::string::iterator it = str.begin();

    std::vector<std::string> tmp_v;

    while (  it = std::find(it, str.end(), CHAR_SEPARATOR), it != str.end()  )
    {
        count_++;

        tmp_v.push_back(std::string(it_prev, it));

        it_prev = ++it;
    }

    if ( !count_ )
    {
        throw std::runtime_error("Message(): Error create! -> count_ == 0");
    };

    ptr_str_ = new char*[count_];
    if ( !ptr_str_ )
    {
        throw std::runtime_error("Message(): Error create! -> ptr_str_ (invalid)");
    }

    for ( int i = 0; i < count_; i++)
    {
        const std::string& str = tmp_v[i];
        int n_char = std::distance(str.begin(), str.end());

        ptr_str_[i] = new char[n_char+1];
        if ( !ptr_str_[i] ) throw std::runtime_error(std::string(__func__) + ": Error create -> i = " + std::to_string(i));

        std::strcpy(ptr_str_[i], str.c_str());
    }
}

cui::Message::~Message()
{
    for ( int i = 0; i < count_; i++) { delete[] ptr_str_[i]; }

    delete[] ptr_str_;
}