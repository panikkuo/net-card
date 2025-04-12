#include "base_handler.hpp"

namespace NetCardID::base {
    BaseHandler::BaseHandler(Json::Value configs, std::string_view kName) {
        Json::Value config = configs[kName.data()];
        kPath = config["path"].asString();
        switch (config["method"]){
            case "POST":
                kMethod = drogon::HttpMethod::Post;
                break;
            case "GET":
                kMethod = drogon::HttpMethod::Get;
                break;
            case "PUT":
                kMethod = drogon::HttpMethod::Put;
                break;
            case "DELETE":
                kMethod = drogon::HttpMethod::Delete;
                break;
            case "PATCH":
                kMethod = drogon::HttpMethod::Patch;
                break;
            case "HEAD":
                kMethod = drogon::HttpMethod::Head;
                break;
            case "OPTIONS":
                kMethod = drogon::HttpMethod::Options;
                break;
        }
        kMethod = static_cast<drogon::HttpMethod>(config["method"].asInt());
        db = db::DbManager::getDbClient();
    }
}