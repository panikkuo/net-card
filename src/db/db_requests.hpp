#include <string_view>

namespace NetCardID::utils::db_request {
    inline constexpr std::string_view kAddUserV1 = "
        INSERT INTO users (username, password_hash) 
        VALUES ($1, $2)
        RETURNING id;
    ";
};