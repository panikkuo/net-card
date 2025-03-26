#pragma once

#include <string>
#include <regex>

namespace NetCardID::utils::validators {
    bool CheckSize(const std::string& value, int min, int max);
    void ValidateUsername(const std::string& username);
    void ValidatePassword(const std::string& password);
}