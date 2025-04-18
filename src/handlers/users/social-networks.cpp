#include "socail-networks.hpp"

namespace NetCardID::users::v1::social_networks::post {
    drogon::Task<drogon::HttpResponsePtr> Handler::RequestHandler(const drogon::HttpRequestPtr& request) {
        drogon::HttpResponsePtr response = drogon::HttpResponse::newHttpResponse();
        std::shared_ptr<Json::Value> json_request = request->getJsonObject();

        models::users::v1::UsersV1SocialNetworksRequest user_request;

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
            LOG_ERROR << "Error parsing JSON: " << exception.what();
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            Json::Value json;
            json["Result"] = "Internal server error";
            co_return response;
        }

        Json::Value added_networks(Json::arrayValue);
        try {
            for (const auto& net : user_request.networks) {

            }
        }
    }
}


// try {
//     for (const auto net : user_request.networks) {
//         drogon::orm::Result result = co_await db->execSqlCoro(NetCardID::db::db_request::kGetNetIdQuery, net.network);

//         if (result.empty()) {
//             LOG_ERROR << "Network type not found: " << net.network;
//             response->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
//             Json::Value json;
//             json["Result"] = "Invalid network" + net.network;
//             response->setBody(json.toStyledString());
//             co_return response;
//         }

//         std::string net_id = result[0]["id"].as<std::string>();
//         co_await db->execSqlCoro(NetCardID::db::db_request::kAddUserNetQuery, user_id, net_id, net.url);
//     }
// }
// catch (const drogon::orm::DrogonDbException &e) {
//     LOG_ERROR << "Database error: " << e.base().what();
//     response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
//     Json::Value json;
//     json["Result"] = "Internal server error";
//     response->setBody(json.toStyledString());
//     co_return response;
// }
// catch (const std::exception& exception) {
//     response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
//     Json::Value json;
//     json["Result"] = "Internal server error";
//     response->setBody(json.toStyledString());
//     co_return response;
// }