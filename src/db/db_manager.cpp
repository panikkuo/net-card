#include "db_manager.hpp"

namespace NetCardID::db {
    std::shared_ptr<drogon::orm::DbClient> DbManager::dbClient_ = nullptr;
    void DbManager::init() {
        std::string connect_str = "postgresql://" +
        std::string(dotenv::getenv("DB_USER")) + ":" +
        std::string(dotenv::getenv("DB_PASSWORD")) + "@" +
        std::string(dotenv::getenv("DB_HOST")) + ":" +
        std::string(dotenv::getenv("DB_PORT")) + "/" +
        std::string(dotenv::getenv("DB_DATABASE"));

        LOG_DEBUG << "Connecting to database: " << connect_str;

        dbClient_ = drogon::orm::DbClient::newPgClient(connect_str, 1, false);
    }

    std::shared_ptr<drogon::orm::DbClient> DbManager::getDbClient() {
        return dbClient_;
    }
}
