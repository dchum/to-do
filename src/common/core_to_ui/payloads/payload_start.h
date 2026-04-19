#pragma once

#include <cstdint>
#include <string>

struct Version {
    uint32_t major_version,
             minor_version;
};

struct StartPayload{
    Version           version;    /** Версия ПО для вывода */
    std::string  name_creator;
    std::string hello_message;    /** Приветственное сообщение */
};