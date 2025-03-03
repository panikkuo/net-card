#include <string_view>
#include "validators.hpp"
#include "consts.hpp"

namespace NetCardID::utils::validators {
    bool CheckSize(const std::string_view& value, int min, int max) {
        return min <= value.size() && value.size() <= max;
    }
    void ValidateUsername(const std::string_view& username) {
        if (!CheckSize(username, NetCardID::utils::consts::kUsernameMinLength, NetCardID::utils::consts::kUsernameMaxLength) 
                || !std::regex_match(username.begin(), username.end(), consts::kUsernamePattern)) {
            throw NetCardID::utils::consts::kInvalidUsernameError;
        }
    }
    void ValidatePassword(const std::string_view& password) {
        if (!std::regex_match(password.begin(), password.end(), NetCardID::utils::consts::kPasswordPattern)) {
            throw NetCardID::utils::consts::kInvalidPasswordError;
        }
    }
}