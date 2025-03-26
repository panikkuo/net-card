#include "users_v1.hpp"

namespace NetCardID::models::users::v1 {
    //TODO: исправить обращение к конст, добавить валидатор
    UsersV1SignUpRequest Parse(const drogon::Json::Value& json) {
        UsersV1SignUpRequest request;

        request.username = NetCardID::utils::extractors::ExtractValueFromJson(json, NetCard::utils::consts::kUsernameField, true).value();
        NetCatdID::utils::validators::ValidateUsername(request.username);

        request.password = NetCardID::utils::extractors::ExtractValueFromJson(json, NetCard::utils::consts::kPasswordField, true).value();
        NetCardID::utils::validators::ValidatePassword(request.password);

        auto networks_opt = NetCardID::utils::extractors::ExtractJsonFromJson(json, NetCard::utils::consts::kNetworksCollection, false);

        if (!networks_opt.has_value()) 
            return request;
        
        auto networks = networks.value();

        for (const auto& network : networks) {
            request.networks.push_back({
                NetCardID::utils::extractors::ExtractValueFromJson(network, NetCard::utils::consts::kNetworkName, true).value(),
                NetCardID::utils::extractors::ExtractValueFromJson(network, NetCard::utils::consts:::kNetworkUrl, true).value()
            });
        }

        return request;
    }
}