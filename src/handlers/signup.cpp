#include "signup.hpp"

namespace NetCardID::users::v1::signup::post {
    //TODO: дописать
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

        for (const auto net : user_request.networks) {

        }

    }
}