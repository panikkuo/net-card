#include "base_handler.hpp"

namespace NetCardID::base {
    BaseHandler::BaseHandler(Json::Value& configs, std::string_view kName) {
        Json::Value config = configs[kName.data()];
        kPath = config["path"].asString();
        std::string methodStr = config["method"].asString();
        if (methodStr == "POST") {
            kMethod = drogon::HttpMethod::Post;
        } else if (methodStr == "GET") {
            kMethod = drogon::HttpMethod::Get;
        } else if (methodStr == "PUT") {
            kMethod = drogon::HttpMethod::Put;
        } else if (methodStr == "DELETE") {
            kMethod = drogon::HttpMethod::Delete;
        } else if (methodStr == "PATCH") {
            kMethod = drogon::HttpMethod::Patch;
        } else if (methodStr == "HEAD") {
            kMethod = drogon::HttpMethod::Head;
        } else if (methodStr == "OPTIONS") {
            kMethod = drogon::HttpMethod::Options;
        };
        db = db::DbManager::getDbClient();
    }
}