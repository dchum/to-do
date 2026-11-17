#include "config.h"

#include <iostream>

#include "json.hpp"

#include "key_input.h"

cui::ConfigStorage::ConfigStorage(std::string_view configFile) noexcept
    :configFile( configFile )
{
}

void cui::ConfigStorage::readConfig(void)
{
    using nlohmann::json;

    json data = json::parse( configFile );
    
    auto bindings = data.at("bindings");

    for (auto it = bindings.begin(); it != bindings.end(); ++it) 
    {
        std::string action = it.key();
        std::cout << "Action: " << action << std::endl;

        std::vector<std::string> keys = it.value();

        if ( keys.empty() ) 
        {
            throw std::runtime_error("No keys found for action: " + action);
        }

        std::cout << "Keys: ";
        for (const auto& key : keys) {
            std::cout << key << " ";
            KeyEvent kevent = cui::parse_key_spec(key);
            std::cout << kevent << " ";
        }
        std::cout << std::endl;
    }
}
