#pragma once

#include <string_view>
#include <regex>

namespace NetCardID::utils::validators {
    bool CheckSize(const std::string_view& value, int min, int max);
    void ValidateUsername(const std::string_view& username);
    void ValidatePassword(const std::string_view& password);
}