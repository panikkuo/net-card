#pragma once

#include <regex>
#include <string_view>
#include <drogon/HttpResponse.h>

namespace SocialCardID::utils {
    namespace consts {
        inline constexpr std::string_view kIdField = "id";

        //user
        inline constexpr std::string_view kUsersCollection = "users";
        
        inline constexpr std::string_view kUsernameField = "username";
        inline constexpr int kUsernameMinLength = 3;
        inline constexpr int kUsernameMaxLength = 20;

        inline constexpr std::string_view kPasswordHashField = "password_hash";
        inline const std::regex kPasswordPattern{"^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[!@#$%^&*()_\\-+=\\[\\]{};':\"\\|,.<>/?]).+$"};
        inline constexpr int kPasswordMinLength = 8;

        //network
        inline constexpr std::string_view kNetworksCollection = "networks";

        inline constexpr std::string_view kNetworkNameField = "name";
        inline constexpr std::string_view kNetworkPictureUrlField = "picture_url";

        //error
        inline constexpr std::pair<drogon::HttpStatusCode, std::string_view> 
            kInvalidUsernameError{drogon::HttpStatusCode::k400BadRequest, "Invalid username"};
        inline constexpr std::pair<drogon::HttpStatusCode, std::string_view>
            kInvalidPasswordError{drogon::HttpStatusCode::k400BadRequest, "Invalid password"};
    }
}