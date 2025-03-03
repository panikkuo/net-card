#include "extractor.hpp"
#include "consts.hpp"

namespace NetCardID::utils::extractor {
    std::optional<std::string> ExtractValueFromJson(const drogon::Json::Value& json, const std::string_view& field, bool required = false) {
        if (json.isMember(field.data())) {
            return std::make_optioanl(json[field.data()].asString());
        }
        if (required) {
            throw errors::ExtractionErrorID(consts::kMissingFieldError, field);
        }
        return std::nullopt;
    }

    std::optional<drohon::Json::Value> ExtractJsonFromJson(const drogon::Json::Value& json, const std::string_view& field, bool required = false) {
        if (json.isMember(field.data())) {
            return std::make_optional(json[field.data()]);
        }
        if (required) {
            throw errors::ExtractionErrorID(consts::kMissingFieldError, field);
        }
        return std::nullopt;
    }
}