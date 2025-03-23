#pragma once

#include <string>

namespace NetCardID::objects::v1 {
    struct User final {
        std::string uuid;
        std::string username;
        std::string password_hash;
    };

    struct Netword final {
        std::string id;
        std::string name;
        std::string picture_url;
    };

    struct Connection final {
        std::string user_uuid;
        std::string network_id;
        std::string url; 
    }
}