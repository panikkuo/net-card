#include "profile.hpp"

namespace NetCardID::users::v1::profile::get {
    drogon::Task<drogon::HttpResponsePtr> Handler(const drogon::HttpRequestPtr& request, std::string username) {
        drogon::HttpResponsePtr response = drogon::HttpResponse::newHttpResponse();

        models::users::v1::UsersV1ProfileRequest user;
        user.username = username;

        try {
            drogon::orn::Reslt result = co_await db->execSqlCoro(NetCardID::db::db_request::kGetInfoByUsernameQuery, username);
            if (result.empty()) {
                response->setStatusCode(drogon::HttpStatusCode::k404NotFound);
                Json::Value json;
                json["Result"] = "User not found";
                response->setBody(json.toStyledString());
                co_return response;
            }

            user.id = result[0]["id"].as<std::string>();
            user.email = result[0]["email"].as<std::string>();
        }
        catch (drogon::exception& e) {
            LOG_ERROR << "Database error: " << e.base().what();
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            Json::Value json;
            json["Result"] = "Internal server error";
            response->setBody(json.toStyledString());
            co_return response;
        }

        try {
            drogon::orm::Result result = co_await db->execSqlCoro(NetCardID::db::db_request::kGetNetworksByIdQuery, user.id);
            user.networks = models::users::v1::ParseNetworks(result);
        }
        catch (drogon::exception& e) {
            LOG_ERROR << "Database error: " << e.base().what();
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            Json::Value json;
            json["Result"] = "Internal server error";
            response->setBody(json.toStyledString());
            co_return response;
        }
        Json::Value json = models::users::v1::Serialize(user);
        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        response->setBody(json.toStyledString());
        co_return response;
    }
}