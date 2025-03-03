#pragma once

#include <string_view>

namespace NetCardID::objects::v1 {
    struct User final {
        std::string_view id;
        std::string_view username;
        std::string_view password_hash;
    };

    struct Netword final {
        std::string_view id;
        std::string_view name;
        std::string_view picture_url;
    };
}