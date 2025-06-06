#pragma once

#include <regex>
#include <string_view>
#include <drogon/HttpResponse.h>

namespace NetCardID::utils::consts {
    inline constexpr std::string_view kUserIdField = "id";

    //user
    inline constexpr std::string_view kUsersCollection = "users";
    
    inline constexpr std::string_view kUsernameField = "username";
    inline constexpr std::string_view kEmailField = "email";
    inline const std::regex kUsernamePattern{"^[a-zA-Z][a-zA-Z0-9_]{2,19}$"};
    inline constexpr int kUsernameMinLength = 3;
    inline constexpr int kUsernameMaxLength = 20;

    inline constexpr std::string_view kPasswordHashField = "password";
    inline const std::regex kPasswordPattern{"^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[!@#$%^&*()_\\-+=\\[\\]{};':\"\\|,.<>/?]).+$"};

    // network
    inline constexpr std::string_view kNetworksCollectionField = "networks";

    inline constexpr std::string_view kNetworkNameField = "network";
    inline constexpr std::string_view kNetworkUrlField = "url";
    inline constexpr std::string_view kNetworkPictureUrlField = "picture_url";

    // db error keys
    inline constexpr std::string_view kUsernameUniqueKeyError = "users_username_key";
    inline constexpr std::string_view kEmailUniqueKeyError = "users_email_key";

    //Validation errors
    inline constexpr std::pair<drogon::HttpStatusCode, std::string_view> 
        kInvalidUsernameError{drogon::HttpStatusCode::k400BadRequest, "Invalid username"};
    inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>
        kInvalidPasswordError{drogon::HttpStatusCode::k400BadRequest, "Invalid password"};
    inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>
        kInvalidJsonError{drogon::HttpStatusCode::k400BadRequest, "Invalid JSON"};


    //Extraction errors
    inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>
        kMissingFieldError{drogon::HttpStatusCode::k400BadRequest, "Missing required field"};
    inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>
        kBadFieldValueError{drogon::HttpStatusCode::k400BadRequest, "Bad value field"};

    //Unknown error
    inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>
        kUnknownError{drogon::HttpStatusCode::k500InternalServerError, "Unknown error"};    
}