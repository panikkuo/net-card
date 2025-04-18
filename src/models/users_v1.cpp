#include "users_v1.hpp"

namespace NetCardID::models::users::v1 {
    UsersV1SignUpRequest Parse(const Json::Value& json) {
        UsersV1SignUpRequest request;

        request.username = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kUsernameField, true).value();
        NetCardID::utils::validators::ValidateUsername(request.username);

        request.password = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kPasswordHashField, true).value();
        NetCardID::utils::validators::ValidatePassword(request.password);

        auto networks_opt = NetCardID::utils::extractor::ExtractJsonFromJson(json, NetCardID::utils::consts::kNetworksCollectionField, false);

        if (!networks_opt.has_value()) 
            return request;
        
        auto networks = networks_opt.value();

        for (const auto& network : networks) {
            UsersV1SignUpRequest::Network net;
            net.network = NetCardID::utils::extractor::ExtractValueFromJson(network, NetCardID::utils::consts::kNetworkNameField, true).value();
            net.url = NetCardID::utils::extractor::ExtractValueFromJson(network, NetCardID::utils::consts::kNetworkUrlField, true).value();
            request.networks.push_back(net);
        }

        return request;
    }

    UsersV1LoginRequest Parse(const Json::Value& json) {
        UsersV1LoginRequest reqeust;

        request.username = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kUsernameField, true).value();
        request.password = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kPasswordHashField, true).value();

        return request;
    }

    Json::Value Serialize(const UsersV1Profile& data) {
        Json:::Value json;
        json["id"] = data.id;
        json["username"] = data.username;
        Json::Value json_nets;
        for (const auto& net : data.networks) {
            Json::Value json_net;
            json_net["network"] = net.network;
            json_net["url"] = net.url;
            json_nets.append(json_net);
        }

        return json;
    }
}