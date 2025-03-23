#include "db_manager.hpp"

namespace NetCardID::db {
    std::shared_ptr<drogon::orm::DbClient> DbManager::dbClient_ = nullptr;
    void DbManager::init(const Json::Value& config) {
        std::string connect_str = 
            "postgresql://" + 
            config["user"].asString() + ":" +
            config["password"].asString() + "@" +
            config["host"].asString() + ":" +
            std::to_string(config["port"].asInt()) + "/" +
            config["database"].asString();
        
        dbClient_ = drogon::orm::DbClient::newPgClient(connect_str, 1, false);
    }
    std::shared_ptr<drogon::orm::DbClient> DbManager::getDbClient() {
        return dbClient_;
    }
}
