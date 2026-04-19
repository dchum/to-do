#pragma once

#include <cstdint>
#include <string>
#include <vector>

enum class TaskStatus : uint8_t   { Pending, InProgress, Done, Cancelled };
enum class TaskPriority : uint8_t { Low, Medium, High, Critical };

struct ListFocusState {
    bool     has_focus = false;
    uint32_t active_task_id;
};

struct Task
{
    uint32_t       id_task;
    std::string    name;
    std::string    description;

    TaskStatus     status;
    TaskPriority   priority;

    uint64_t time_creation;
    std::vector<std::string> tags;
};

struct MainPayload{
    std::vector<Task> tasks;
    ListFocusState    focus;
    std::string       view_hint;
};
