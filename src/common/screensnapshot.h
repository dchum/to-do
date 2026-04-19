#pragma once

#include <cstdint>
#include <string>
#include <variant>
#include <vector>

#include "payloads/payload_main.h"
#include "payloads/payload_setting.h"
#include "payloads/payload_start.h"
#include "commands.h"

namespace common {

using WindowPayload = std::variant< MainPayload, StartPayload, SettingsPayload >;

enum class WindowType { Start, Main, Settings };

struct SnapshotMetadata {
    uint64_t              id;    /* Уникальный идентификатор каждого снимка*/
    uint32_t         version;    /* Версия снимка, принимающая сторона обязана поддерживать эту версию или выше */
    WindowType   type_window;    /* Тип окна, для которого пришли обновления */
    std::string producer_tag;    /* Отправитель снимка    */
    uint64_t   time_creation;    /* Время создания снимка */
};

struct ScreenSnapshot {
    SnapshotMetadata         meta_info;
    WindowPayload              payload;
    std::vector<CommandId> command_bar;
};

}//namespace common
