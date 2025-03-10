#pragma once

#include <Json/json.h>
#include <string>
#include <optional>

namespace NetCardID::utils::extractor {
    std::optional<std::string> ExtractValueFromJson(const Json::Value& json, const std::string_view& field, bool required = false);
    std::optional<Json::Value> ExtractJsonFromJson(const Json::Value& json, const std::string_view& field, bool required = false);
}