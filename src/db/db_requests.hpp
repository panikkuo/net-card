#include <string>

namespace NetCardID::db::db_request {
    const std::string kAddUserQuery = "INSERT INTO users (username, password) VALUES($1, $2) RETURNING id";
    const std::string kAddUserNetQuery = "INSERT INTO connections (user_id, netword_id, url) VALUES($1, $2, $3)";
    const std::string kGetNetIdQuery = "SELECT id FROM networks WHERE network = $1";
};