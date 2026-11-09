#include "config.h"

#include <fstream>

#include "json/json.hpp"

#include "input.h"

cui::ConfigStorage::ConfigStorage(std::string_view configFile) noexcept
    :configFile( configFile )
{
}

void cui::ConfigStorage::readConfig(void)
{
    std::ifstream file(configFile);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open config file: " + configFile);
    }

    using nlohmann::json;

    json data = json::parse( file );

    auto bindings = data["bindings"];

    for (auto it = bindings.begin(); it != bindings.end(); ++it) {
        std::string action = it.key();
        std::cout << "Action: " << action << std::endl;

        std::vector<std::string> keys = it.value();

        if (keys.empty()) 
        {
            throw std::runtime_error("No keys found for action: " + action);
        }

        std::cout << "Keys: "; 
        for (const auto& key : keys) {
            std::cout << key << " ";
            KeyEvent kevent = parse_key_spec(key);
            std::cout << kevent << " ";


        }
        std::cout << std::endl;

    
    }
}
