#include "errors.hpp"

namespace NetCardID::utils::errors {

    //Validation error
    ValidationErrorID::ValidationErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message) 
        : message_(std::string(message.second)), code_(message.first) {}

    std::string ValidationErrorID::error() const {
        Json::Value jsonError;
        jsonError["Validation-error"] = message_;
        return jsonError.toStyledString();
    }

    drogon::HttpStatusCode ValidationErrorID::code() const {
        return code_;
    }


    //Extraction error
    ExtractionErrorID::ExtractionErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message, const std::string_view& field) {
        message_ = std::string(message.second) + " " + std::string(field);
        code_ = message.first;
    }

    std::string ExtractionErrorID::error() const {
        Json::Value jsonError;
        jsonError["Extraction-error"] = message_;
        return jsonError.toStyledString();
    }

    drogon::HttpStatusCode ExtractionErrorID::code() const {
        return code_;
    }
}