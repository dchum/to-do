#pragma once

#include <cstdint>
#include <string>
#include <variant>
#include <vector>

#include "payloads/payload_main.h"
#include "payloads/payload_setting.h"
#include "payloads/payload_start.h"
#include "commands_id.h"
#include "header_message.h"

namespace common {

using WindowPayload = std::variant< MainPayload, StartPayload, SettingsPayload >;

enum class WindowType { Start, Main, Settings };

struct SnapshotMetadata {
    HeaderMessage     header;
    WindowType   type_window;    /* Тип окна, для которого пришли обновления */
    uint64_t   time_creation;    /* Время создания снимка */
};

struct ScreenSnapshot {
    SnapshotMetadata         meta_info;
    WindowPayload              payload;
    std::vector<CommandId> command_bar;
};

}//namespace common
