#include "extractors.hpp"

namespace NetCardID::utils::extractor {
    std::optional<std::string> ExtractValueFromJson(const Json::Value& json, const std::string_view& field, bool required) {
        if (json.isMember(field.data())) {
            return std::make_optional(json[field.data()].asString());
        }
        if (required) {
            throw NetCardID::utils::errors::ExtractionErrorID(consts::kMissingFieldError, field);
        }
        return std::nullopt;
    }

    std::optional<Json::Value> ExtractJsonFromJson(const Json::Value& json, const std::string_view& field, bool required) {
        if (json.isMember(field.data())) {
            return std::make_optional(json[field.data()]);
        }
        if (required) {
            throw NetCardID::utils::errors::ExtractionErrorID(consts::kMissingFieldError, field);
        }
        return std::nullopt;
    }
}