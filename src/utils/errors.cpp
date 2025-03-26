#include "errors.hpp"

namespace NetCardID::utils::errors {

    //Validation error
    ValidationErrorID::ValidationErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message) 
        : message_(message.second), code_(message.first) {}

    std::string ValidationErrorID::error() {
        Json::Value jsonError;
        return message_;
    }

    drogon::HttpStatusCode ValidationErrorID::code() {
        return code_;
    }


    //Extraction error
    ExtractionErrorID::ExtractionErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message, const std::string_view& field) {
        message_ = message.second + " " + field;
        code_ = message.first;
    }

    std::string ExtractionErrorID::error() {
        return message_;
    }

    drogon::HttpStatusCode ExtractionErrorID::code() {
        return code_;
    }
}