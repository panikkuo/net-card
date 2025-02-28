#pragma once

#include <string_view>
#include <regex>

#include "consts.hpp"

namespace SocialCardID::utils::validators {
    bool CheckSize(const std::string_view& value, int min, int max);
    void ValidateUsername(const std::string_view& username);
    void ValidatePassword(const std::string_view& password);
}