#include "users_v1.hpp"

namespace NetCardID::models::users::v1 {
    //TODO: исправить обращение к конст, добавить валидатор
    UsersV1SignUpRequest Parse(const drogon::Json::Value& json) {
        UsersV1SignUpRequest request;

        request.username = NetCard::ExtractValueFromJson(json, NetCard::utils::consts::kUsernameField, true).value();

        request.password = NetCard::ExtractValueFromJson(json, NetCard::models::users::v1::kPassword, true).value();

        auto networks_opt = NetCard::ExtractValueFromJson(json, NetCard::models::users::v1::kNetworks, false);

        if (!networks_opt.has_value()) 
            return request;
        
        auto networks = networks.value();

        for (const auto& network : networks) {
            request.networks.push_back({
                NetCard::ExtractValueFromJson(network, NetCard::models::users::v1::kNetworkName, true).value(),
                NetCard::ExtractValueFromJson(network, NetCard::models::users::v1::kNetworkUrl, true).value()
            });
        }

        return request;
    }
}