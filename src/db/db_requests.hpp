#include <string>

namespace NetCardID::db::db_request {
    const std::string kAddUserQuery = "INSERT INTO users (username, password_hash) VALUES($1, $2) RETURNING id";
    const std::string kAddUserNetQuery = "INSERT INTO connections (user_id, netword_id, url) VALUES($1, $2, $3)";
    const std::string kGetNetIdQuery = "SELECT id FROM networks WHERE network = $1";
    const std::string kGetUserByUsernameQuery = "SELECT id, username, password_hash FROM users WHERE id = $1";
    const std::string kGetInfoByUsernameQuery = "SELECT id FROM users WHERE id = $1";
    const std::string kGetNetsByIdQuery = "SELECT name, "
};