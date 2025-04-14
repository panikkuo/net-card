#include <string>
#include <string_view>
#include <memory>
#include <drogon/drogon.h>
#include <json/json.h>

#include "db/db_manager.hpp"

namespace NetCardID::base {
    class BaseHandler {
    public:
        BaseHandler(Json::Value& configs, std::string_view kName);
        virtual drogon::Task<drogon::HttpResponsePtr> RequestHandler(const drogon::HttpRequestPtr& request) = 0;
        std::string kPath;
        drogon::HttpMethod kMethod;
        
    protected:
        std::shared_ptr<drogon::orm::DbClient> db;
    };
}