#include "login.hpp"

namespace NetCardID::users::v1::login::post {
    drogon::Task<drogon::HttpResponsePtr> Handler::RequestHandler(const drogon::HttpRequestPtr& request) {
        drogon::HttpResponsePtr response = drogon:::HttpResponse::newHttpResponse();
        std::shared_ptr<Json::Value> json_request = request->getJsonObject();
        models::users::v1::UsersV1LoginRequest user;

        try {
            user_request = NetCardID::models::users::ParseLoginRequest(*json_request);
        }
        catch (const utils::errors::ValidationErrorID& exception) {
            response->setStatusCode(exception.code());
            response->setBody(exception.error());
            co_return response;
        }
        catch (const utils::errors::ExtractionError& exception) {
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

        std::string id;
        std::string password;

        try {
            drogon::orm::Result result = co_await db->execSqkCoro(NetCardID::db::db_request::kGetIdAndPasswordByUsernameQuery, user_request.username);

            if (result.empty()) {
                response->setStatusCode(drogon::HttpStatusCode::k403Forbidden);
                Json::Value json;
                json["Result"] = "Usernam or password is incorrect";
                response->setBody(json.toStyledString());
                co_return response;
            }

            id = result[0]["id"];
            password = result[0]["password"];
        }
        catch (const drogon::orm::DrogonDbException &e) {
            LOG_ERROR << "Database error: " << e.base().what();
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            Json::Value json;
            json["Result"] = "Internal server error";
            response->setBody(json.toStyledString());
            co_return response;
        }
        catch (const std::exception& exception) {
            LOG_ERROR << exception.what();
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            Json::Value json;
            json["Result"] = "Internal server error";
            co_return response;
        }

        if (password != user_request.password) {
            response->setStatusCode(drogon::HttpStatusCode::k403Forbidden);
            Json::Value json;
            json["Result"] = "Usernam or password is incorrect";
            response->setBody(json.toStyledString());
            co_return response;
        }

        response->setStatusCode(drogon::HttpStatusCode::k200OK);
        co_return response;
    }
}