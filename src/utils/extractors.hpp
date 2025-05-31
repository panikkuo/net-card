#pragma once


#include <string>
#include <vector>
#include <optional>

#include <Json/json.h>

#include "consts.hpp"
#include "errors.hpp"

namespace NetCardID::utils::extractor {
    std::optional<std::string> ExtractValueFromJson(const Json::Value& json, const std::string_view& field, bool required = false);
    std::optional<Json::Value> ExtractJsonFromJson(const Json::Value& json, const std::string_view& field, bool required = false);
    std::optional<std::vector<Json::Value>> ExtractArrayOfJsonsFromJson(const Json::Value& json, const std::string_view& field, bool required = false);
}