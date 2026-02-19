#include "cui_lib.h"


#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <memory>

constexpr char CHAR_SEPARATOR = '~';

cui::Message::Message( const std::string &str )//FIXME - почему в конце пишется нижнее подчеркивание
{
    std::istringstream iss(str);
    std::string token;
    std::vector< std::string > tmp_v;

    while ( std::getline( iss, token, CHAR_SEPARATOR ) ) {
        tmp_v.push_back(std::move(token));
    }

    swap( strings_, tmp_v );
}


cui::CStringArray::CStringArray(const Message& message) {
    const auto& tokens = message.tokens();

    pointers.reserve(tokens.size());

    for (const auto& s : tokens) {
        auto buf = std::make_unique<char[]>(s.size()+1);
        std::strcpy(buf.get(), s.c_str());

        std::cerr << buf.get() << std::endl;
        pointers.push_back(buf.release());
        std::cerr << buf.get() << std::endl;
    }

    for (const auto& s : pointers) {
        std::cerr << s << std::endl;
    }
}
