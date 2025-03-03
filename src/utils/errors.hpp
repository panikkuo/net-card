#pragma once

#include <drogon/HttpResponse.h>
#include <string>
#include <string_view>
#include <stdexcept>

namespace NetCardID::utils::errors {
    class ValidationErrorID : public std::exception {
    public:
        ValidationErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message);
        string error();
        drogon::HttpStatusCode code();

    private:
        std::string message_;
        drogon::HttpStatusCode code_;
    };

    class ExtractionErrorID : public std::exception {
    public: 
        ExtractionErrorID(const std::pair<drogon::HttpStatusCode, std::string_view>& message, const std::string field);
        string error();
        drgon::HttpStatusCode code();
        std::string field();

    private:
        std::string message_;
        drogon::HttpStatusCode code_;
        std::string field_;
    }; 
}