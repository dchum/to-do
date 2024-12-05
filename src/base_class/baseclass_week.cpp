#include "baseclass_week.h"

#include <numeric>




Week::Week()
{
    _days_week.reserve(static_cast<std::size_t>(WEEKDAY::NUM_DAY_WEEK));
    _days_week.shrink_to_fit();
}

void Week::update(void)
{
    _count_all_task = std::accumulate(_days_week.begin(), _days_week.end(), 0, 
                                    [](int curr_sum, const Day &day)
                                    { return  curr_sum + day.count_all_task(); });

    _count_done_task = std::accumulate(_days_week.begin(), _days_week.end(), 0, 
                                    [](int curr_sum, Day &day)
                                    { return  curr_sum + day.count_done_task(); });
}