#include "global_lib.h"

std::ostream &operator<<(std::ostream &os, const vector<string>& vector_to_string)
{
    vector<string>::const_iterator iter = vector_to_string.cbegin();
    
    os <<"{";
    for (; iter != vector_to_string.cend(); iter++)
    {
        os << *iter;
        if (iter != vector_to_string.cend() - 1)
            os << " ";
    }
    os << "} ";

    return os;
}