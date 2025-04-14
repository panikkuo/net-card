#include "signup.hpp"

namespace NetCardID::users::v1::signup::post {
    drogon::Task<drogon::HttpResponsePtr> Handler::RequestHandler(const drogon::HttpRequestPtr& request) {
        drogon::HttpResponsePtr response = drogon::HttpResponse::newHttpResponse();
        std::shared_ptr<Json::Value> json_request = request->getJsonObject();
        models::users::v1::UsersV1SignUpRequest user_request;

        try {
            user_request = models::users::v1::Parse(*json_request);
        }
        catch (const utils::errors::ValidationErrorID& exception) {
            response->setStatusCode(exception.code());
            response->setBody(exception.error());
            co_return response;
        }
        catch (const utils::errors::ExtractionErrorID& exception) {
            response->setStatusCode(exception.code());
            response->setBody(exception.error());
            co_return response;
        }
        catch (const std::exception& exception) {
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            Json::Value json;
            json["Result"] = "Internal server error";
            co_return response;
        }

        std::string user_id;

        try {
            drogon::orm::Result result = co_await db->execSqlCoro(NetCardID::db::db_request::kAddUserQuery, user_request.username, user_request.password);
            user_id = result[0]["id"].as<std::string>();
        }
        catch (const drogon::orm::DrogonDbException &e) {
            std::string msg = e.base().what();
            if (msg.find(NetCardID::utils::consts::kUniqueKeyError.data()) != std::string::npos) {
                response->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
                Json::Value json;
                json["Result"] = "User with this username already exists";
                co_return response;
            }

            LOG_ERROR << "Database error: " << e.base().what();
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            Json::Value json;
            json["Result"] = "Internal server error";
            co_return response;
        }

        try {
            for (const auto net : user_request.networks) {
                drogon::orm::Result result = co_await db->execSqlCoro(NetCardID::db::db_request::kGetNetIdQuery, net.network);
                std::string net_id = result[0]["id"].as<std::string>();
                co_await db->execSqlCoro(NetCardID::db::db_request::kAddUserNetQuery, user_id, net_id, net.url);
            }
        }
        catch (const drogon::orm::DrogonDbException &e) {
            LOG_ERROR << "Database error: " << e.base().what();
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            Json::Value json;
            json["Result"] = "Internal server error";
            co_return response;
        }

        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        Json::Value json;
        json["Result"] = "User was successfully added";
        co_return response;
    }
}