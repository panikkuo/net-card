#include "extractors.hpp"

namespace NetCardID::utils::extractor {
    std::optional<std::string> ExtractValueFromJson(const Json::Value& json, const std::string_view& field, bool required) {
        if (json.isArray() || json.isObject()) {
            throw NetCardID::utils::errors::ExtractionError(consts::kBadFieldValueError, field);
        }
        if (json.isMember(field.data())) {
            return std::make_optional(json[field.data()].asString());
        }
        if (required) {
            throw NetCardID::utils::errors::ExtractionError(consts::kMissingFieldError, field);
        }
        return std::nullopt;
    }

    std::optional<Json::Value> ExtractJsonFromJson(const Json::Value& json, const std::string_view& field, bool required) {
        if (!json.isObject()) {
            throw NetCardID::utils::errors::ExtractionError(consts::kBadFieldValueError, field);
        }
        if (json.isMember(field.data())) {
            return std::make_optional(json[field.data()]);
        }
        if (required) {
            throw NetCardID::utils::errors::ExtractionError(consts::kMissingFieldError, field);
        }
        return std::nullopt;
    }

    std::optional<std::vector<Json::Value>> ExtractArrayOfJsonsFromJson(const Json::Value& json, const std::string_view& field, bool required) {
        if (!json.isArray()) {
            throw NetCardID::utils::errors::ExtractionError(consts::kBadFieldValueError, field);
        }
        if (json.isMember(field.data())) {
            std::vector<Json::Value> result;
            for (const auto& item : json[field.data()]) 
                result.push_back(item);

            return std::make_optional(result);
        }
        if (required) {
            throw NetCardID::utils::errors::ExtractionError(consts::kMissingFieldError, field);
        }

        return std::nullopt;
    }
}