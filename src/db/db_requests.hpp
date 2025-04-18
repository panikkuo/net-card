#include <string>

namespace NetCardID::db::db_request {
    const std::string kAddUserQuery = "INSERT INTO users (username, password, email) VALUES($1, $2, $3) RETURNING id";
    const std::string kAddUserNetworkQuery = "INSERT INTO connections (user_id, netword_id, url) VALUES($1, $2, $3)";
    const std::string kGetNetwokIdQuery = "SELECT id FROM networks WHERE network = $1";
    const std::string kGetIdAndPasswordByUsernameQuery = "SELECT id, password FROM users WHERE id = $1";
    const std::string kGetInfoByUsernameQuery = "SELECT id, email FROM users WHERE id = $1";
    const std::string kGetNetworksByIdQuery = "SELECT networks.name, connections.url FROM connections JOIN networks ON connections.network_id = networks.id WHERE connections.user_id = $1";
    const std::string kGetAllnetworksQuery = "SELECT network, picture_url FROM networks";
}