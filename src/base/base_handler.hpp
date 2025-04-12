// const static std::string kName = "/api/v1/users/signup";
// const static drogon::HttpMethod kMethod = drogon::Post;
// private:
// const static std::shared_ptr<drogon::orm::DbClient> db = db::DbManager::getDbClient();

#include <string>
#include <memory>
#include <drogon/drogon.h>
#include <json/json.h>

#include "db/db_manager.hpp"

namespace NetCardID::base {
    class BaseHandler {
    public:
        BaseHandler(Json::Value configs, std::string_view kName);
        virtual drogon::Task<drogon::HttpResponsePtr> RequestHandler(const drogon::HttpRequestPtr& request);
        std::string kPath;
        drogon::HttpMethod kMethod;
        
    protected:
        std::shared_ptr<drogon::orm::DbClient> db;
    };
}