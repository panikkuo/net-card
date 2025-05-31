#pragma once

#include <vector>
#include <Json/json.h>
#include <drogon/drogon.h>

#include "utils/extractors.hpp"
#include "utils/validators.hpp"
#include "utils/consts.hpp"

namespace NetCardID::models::users::v1 {

    struct UsersV1SignUpRequest final {
        std::string username;
        std::string password;
        std::string email;
    };
    UsersV1SignUpRequest ParseSignUpRequest(const Json::Value& json);


    struct UsersV1LoginRequest final {
        std::string username;
        std::string password;
    };
    UsersV1LoginRequest ParseLoginRequest(const Json::Value& json);


    struct UsersV1ProfileRequest final {
        std::string id;
        std::string username;
        std::string email;
        struct Network {
            std::string network;
            std::string url;
        };
        std::vector<Network> networks;
    };
    std::vector<UsersV1ProfileRequest::Network> ParseNetworks(drogon::orm::Result result);
    Json::Value Serialize(const UsersV1ProfileRequest& data);

    
    struct UsersV1SocialNetworksRequest final {
        std::string user_id;
        struct Network {
            std::string network;
            std::string url;
        };
        std::vector<Network> networks;
    };
    UsersV1SocialNetworksRequest ParseSocialNetworksRequest(const Json::Value& json);
}