#include "baseclass_week.h"

#include <numeric>




Week::Week()
{
    _days_week.reserve(static_cast<std::size_t>(WEEKDAY::NUM_DAY_WEEK));
    _days_week.shrink_to_fit();
}

// void Week::update(void)
// {
    
// }