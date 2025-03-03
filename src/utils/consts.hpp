#pragma once

#include <regex>
#include <string_view>
#include <drogon/HttpResponse.h>

namespace NetCardID::utils {
    namespace consts {
        inline constexpr std::string_view kIdField = "id";

        //user
        inline constexpr std::string_view kUsersCollection = "users";
        
        inline constexpr std::string_view kUsernameField = "username";
        inline const std::regex kUsernamePattern{"^[a-zA-Z][a-zA-Z0-9_]{2,19}$"};
        inline constexpr int kUsernameMinLength = 3;
        inline constexpr int kUsernameMaxLength = 20;

        inline constexpr std::string_view kPasswordHashField = "password_hash";
        inline const std::regex kPasswordPattern{"^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[!@#$%^&*()_\\-+=\\[\\]{};':\"\\|,.<>/?]).+$"};

        // network
        inline constexpr std::string_view kNetworksCollection = "networks";

        inline constexpr std::string_view kNetworkNameField = "name";
        inline constexpr std::string_view kNetworkPictureUrlField = "picture_url";

        //Validation errors
        inline constexpr std::pair<drogon::HttpStatusCode, std::string_view> 
            kInvalidUsernameError{drogon::HttpStatusCode::k400BadRequest, "Invalid username"};
        inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>
            kInvalidPasswordError{drogon::HttpStatusCode::k400BadRequest, "Invalid password"};
        inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>
            kInvalidJsonError{drogon::HttpStatusCode::k400BadRequest, "Invalid JSON"};
        inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>

        //Extraction errors
            kMissingFieldError{drogon::HttpStatusCode::k400BadRequest, "Missing required field"};
        inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>

        //Unknown error
            kUnknownError{drogon::HttpStatusCode::k500InternalServerError, "Unknown error"};
    }
}