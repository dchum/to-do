#pragma once 

#include <optional>
#include <map>
#include <string>

#include "commands.h"

class CommandRegistry {

public:
    // Инициализируется один раз при старте программы
    static void init() 
    {
        m_string_to_id = {
            {"CreateTask",   common::CommandId::CreateTask},
            {"DeleteTask",   common::CommandId::DeleteTask},
            {"ExitProgram",  common::CommandId::ExitProgram},
            {"NavigateUp",   common::CommandId::NavigateUp},
            {"NavigateDown", common::CommandId::NavigateDown},
            {"NavigateLeft", common::CommandId::NavigateLeft},
            {"NavigateRight",common::CommandId::NavigateRight},
            {"OnSetting",    common::CommandId::OnSetting},
            {"OffSetting",   common::CommandId::OffSetting}
        };
        
        for (const auto& pair : m_string_to_id) 
        {
            m_id_to_string[pair.second] = pair.first;
        }
    }

    static std::optional<common::CommandId> parse(const std::string& name) 
    {
        auto it = m_string_to_id.find(name);
        if (it != m_string_to_id.end()) 
        {
            return it->second;
        }
        return std::nullopt; // Не найдено
    }

    static std::string toString(common::CommandId id) 
    {
        auto it = m_id_to_string.find(id);
        return it != m_id_to_string.end() ? it->second : "Unknown";
    }

private:
    static inline std::map<std::string, common::CommandId> m_string_to_id;
    static inline std::map<common::CommandId, std::string> m_id_to_string;
};