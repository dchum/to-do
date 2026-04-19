#pragma once

#include <cstdint>
#include <optional>
#include <vector>
#include <string>
#include <variant>

enum class SettingType : uint8_t { 
    Bool, Integer, Float, String, Enum
};

template <SettingType T>
struct SettingConstraints;

template <>
struct SettingConstraints<SettingType::Bool> {
    static constexpr bool default_value = false;
    bool current_value;
};

template <>
struct SettingConstraints<SettingType::Integer> {
    static constexpr int default_value = 0;
    int current_value;
    int max_value, min_value;
};

template <>
struct SettingConstraints<SettingType::Float> {
    static constexpr float default_value = 0;
    float current_value;
    float max_value, min_value;
};

template <>
struct SettingConstraints<SettingType::Enum> {
    std::string default_value;
    std::vector<std::string> enum_options;
};

struct SettingDescriptor {
    SettingType type_setting;
    std::variant< SettingConstraints< SettingType::Bool>, SettingConstraints<SettingType::Integer>, 
                  SettingConstraints<SettingType::Float>, SettingConstraints<SettingType::Enum> > 
                  settings_value;
    std::string   label;           // Текст для отображения
    std::string   description;     // Подсказка/тултип //TODO
};


struct SettingsPayload {
    std::vector<SettingDescriptor> settings;
};