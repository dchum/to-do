#pragma once

#include <cstdint>
#include <optional>
#include <vector>
#include <string>
#include <variant>

enum class SettingType : uint8_t { 
    Bool, Integer, Float, String, Enum
};

template <SettingType Type>
struct SettingConstraints {
    static_assert(false, 
        "=================================================================\n"
        "   No specialization of SettingConstraints<> for this type!\n\n"
        "=================================================================");
};

struct SettingConstraintsBool {
    static constexpr bool default_value = false;
    bool current_value;
};

struct SettingConstraintsInteger {
    static constexpr int default_value = 0;
    int current_value;
    int max_value, min_value;
};

struct SettingConstraintsFloat {
    static constexpr float default_value = 0;
    float current_value;
    float max_value, min_value;
};

struct SettingConstraintsEnum {
    std::string default_value;
    std::vector<std::string> enum_options;
};

struct SettingConstraintsString {
    std::string value;
};


template <>
struct SettingConstraints<SettingType::Bool> {
    using type = SettingConstraintsBool;
};

template <>
struct SettingConstraints<SettingType::Integer> {
    using type = SettingConstraintsInteger;
};

template <>
struct SettingConstraints<SettingType::Float> {
    using type = SettingConstraintsFloat;
};

template <>
struct SettingConstraints<SettingType::String> {
    using type = SettingConstraintsString;
};

template <>
struct SettingConstraints<SettingType::Enum> {
    using type = SettingConstraintsEnum;
};

template <SettingType id>
struct SettingDescriptor {
    constexpr SettingType type_setting = id;
    std::string label;           // Текст для отображения
    std::string description;     // Подсказка/тултип //TODO
    typename SettingConstraints<id>::type settings_value;
};

using SettingVariant = std::variant<
    SettingDescriptor<SettingType::Bool>,
    SettingDescriptor<SettingType::Integer>,
    SettingDescriptor<SettingType::Float>,
    SettingDescriptor<SettingType::String>,
    SettingDescriptor<SettingType::Enum>
>;


struct SettingsPayload {
    std::vector<SettingVariant> settings;
};