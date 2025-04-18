#pragma once

#include <vector>
#include <Json/json.h>

#include "utils/extractors.hpp"
#include "utils/validators.hpp"
#include "utils/consts.hpp"

namespace NetCardID::models::users::v1 {

    struct UsersV1SignUpRequest final {
        std::string username;
        std::string password;
        struct Network {
            std::string network;
            std::string url;
        };
        std::vector<Network> networks;
    };

    UsersV1SignUpRequest Parse(const Json::Value& json);

    struct UsersV1LoginRequest final {
        std::string username;
        std::string password;
    }

    UsersV1LoginRequest Parse(const Json::Value& json);

    stuct UsersV1ProfileRequest final {
        std::string id;
        std::string username;
        struct Network {
            std::string network;
            std::string url;
        }
        std::vector<Network> networks;
    }

    Json::Value Serialize(const UsersV1ProfileRequest& data);
}