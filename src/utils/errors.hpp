#pragma once

#include <drogon/HttpResponse.h>
#include <Json/Json.h>

#include <string>
#include <string_view>
#include <stdexcept>

namespace NetCardID::utils::errors {
    class ValidationErrorID : public std::exception {
    public:
        ValidationErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message);
        std::string error() const;
        drogon::HttpStatusCode code() const;

    private:
        std::string message_;
        drogon::HttpStatusCode code_;
    };

    class ExtractionError : public std::exception {
    public: 
        ExtractionError(const std::pair<drogon::HttpStatusCode, std::string_view>& message, const std::string_view& field);
        std::string error() const;
        drogon::HttpStatusCode code() const;
    private:
        std::string message_;
        drogon::HttpStatusCode code_;
    }; 
}