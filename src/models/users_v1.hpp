#pragma once

#include <drogon/Json.h>

#include "extractor.hpp"
#include "validators.hpp"
#include "consts.hpp"

namespace NetCardID::models::users::v1 {

    struct UsersV1SignUpRequest final {
        std::string username;
        std::string password;
        struct Networks {
            std::string name;
            std::string picture_url;
        } network;
    };

    UsersV1SignUpRequest Parse(const drogon::Json::Value json);
}