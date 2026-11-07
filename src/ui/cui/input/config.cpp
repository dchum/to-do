#include "config.h"

#include "json/json.hpp"

cui::ConfigStorage::ConfigStorage(std::string_view configFile) noexcept
    :configFile( configFile )
{
}

void cui::ConfigStorage::readConfig(void)
{
    using nlohmann::json;

    json data = json::parse( configFile );
}
