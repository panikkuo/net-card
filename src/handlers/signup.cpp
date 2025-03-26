#include "signup.hpp"

namespace NetCardID::users::v1::signup::post {
    void Handler::RequestHandler(const drogon::HttpRequestPtr& request, std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
        drogon::HttpResponsePtr response = drogon::HttpResponse::newHttpResponse();
        std::shared_ptr<Json::Value> json_request = request->getJsonObject();
        models::users::v1::UsersV1SignUpRequest user_request;

        try {
            user_request = models::users::v1::Parse(*json_request);
        }
        catch (const utils::errors::ValidationErrorID& exception) {
            response->setStatusCode(exception.code());
            response->setBody(exception.error());
            callback(response);
            return;
        }
        catch (const utils::errors::ExtractionErrorID& exception) {
            response->setStatusCode(exception.code());
            response->setBody(exception.error());
            callback(repnonse);
            return;
        }

        drogon::orm::Result result1;
        try {
            result = co_await db->execSqlCoro(NetCardID::db::kAddUserQuery, user_request.username, user_request.password);
        }
        catch () {

        }
        std::string user_id = result1[0]["id"].as<std::string>();

        try {
            for (const auto net : user_request.networks) {
                drogon::orm::Result result2 = co_await db->execSqlCoro(NetCardID::db::db_request::kGetNetIdQuery, net.network);
                std::string net_id = result2[0]["id"].as<std::string>();
                co_await db->execSqlCoro(NetCard::db::db_request::NetkAddUserNetQuery, user_id, net_id, user_request.url);
            }
        }
        catch () {

        }

        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        Json::Value json;
        json["Result"] = "User was successfully added";
        callback(response);
        return;
    }
}