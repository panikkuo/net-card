#include "validators.hpp"

namespace SocialCardID::utils::validators {
    bool CheckSize(const std::string_view& value, int min, int max) {
        return min <= value.size() && value.size() <= max;
    }
    void ValidateUsername(const std::string_view& username) {

    }
    void ValidatePassword(const std::string_view& password) {
        
    }
}