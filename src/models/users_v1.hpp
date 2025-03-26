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

    UsersV1SignUpRequest Parse(const drogon::Json::Value& json);
}