#include <drogon/HttpResponse.h>

#include "errors.hpp"

namespace NetCardID::utils::errors {
    ValidationErrorID::ValidationErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message) 
        : message_(message.second), code_(message.first) {}

    std::string ValidationErrorID::error() {
        return message_;
    }

    drogon::HttpStatusCode ValidationErrorID::code() {
        return code_;
    }


    ExtractionErrorID::ExtractionErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message, const std::string field) 
        : message_(message.second), code_(message.first), field_(field) {}

    std::string ExtractionErrorID::error() {
        return message_;
    }

    drogon::HttpStatusCode ExtractionErrorID::code() {
        return code_;
    }

    std::string ExtractionErrorID::field() {
        return field_;
    }
}