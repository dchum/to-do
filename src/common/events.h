/**
 * @file events.h
 * @author chumakov (<d.tchumackov2013@yandex.ru>)
 * @brief 
 * @version 0.1
 * @date 2026-10-06
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <cstdint>
#include <variant>
#include <string>


enum class EventId : uint16_t {
    CreateTask,
};

struct CreateTaskEvent {
    std::string name;         /* Название задачи */
};

using EventPayload = std::variant<
    CreateTaskEvent,
>;

struct Event {
    EventId event_id;        /* Идентификатор события */
    EventPayload payload; 
};