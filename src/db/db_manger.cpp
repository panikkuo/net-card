#include <memory>
#include <drogon/orm/DbClient.h>
#include <drogon/Json.h>

namespace NetCardID::db {
    static void DbManager::init(const Json::Value& config) {
        std::string connect_str = 
            "postgresql://" + 
            config["user"].asString() + ":" +
            config["password"].asString() + "@" +
            config["host"].asString() + ":" +
            std::to_string(config["port"].asInt()) + "/" +
            config["database"].asString();
        
        client_ = drogon::orm::DbClient::newPgClient(connect_str);
    }
    static std::shared_ptr<drogon::orm::DbClient> DbManager::getDbClient() {
        return client_;
    }
}