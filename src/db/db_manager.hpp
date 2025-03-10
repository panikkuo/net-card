#pragma once

#include <memory>
#include <drogon/orm/DbClient.h>
#include <Json/json.h>

namespace NetCardID::db {
    class DbManager {
    public:
        static void init(const Json::Value& config);
        static std::shared_ptr<drogon::orm::DbClient> getDbClient();
    private:
        static std::shared_ptr<drogon::orm::DbClient> dbClient_;
    };
}