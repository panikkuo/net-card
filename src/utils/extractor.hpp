#pragma once

#include <drogon/Json.h>
#include <string>

namespace NetCardID::utils::extractor {
    std::optional<std::string> ExtractValueFromJson(const drogon::Json::Value& json, const std::string_view& field, bool required = false);
    std::optional<drogon::Json::Value> ExtractJsonFromJson(const drogon::Json::Value& json, const std::string_view& field, bool required = false);
}