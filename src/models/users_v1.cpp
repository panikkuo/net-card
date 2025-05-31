#include "users_v1.hpp"

namespace NetCardID::models::users::v1 {
    UsersV1SignUpRequest ParseSignUpRequest(const Json::Value& json) {
        UsersV1SignUpRequest request;

        request.username = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kUsernameField, true).value();
        NetCardID::utils::validators::ValidateUsername(request.username);

        request.password = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kPasswordHashField, true).value();
        NetCardID::utils::validators::ValidatePassword(request.password);

        request.email = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kEmailField, true).value();

        return request;
    }

    UsersV1LoginRequest ParseLoginRequest(const Json::Value& json) {
        UsersV1LoginRequest request;

        request.username = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kUsernameField, true).value();
        request.password = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kPasswordHashField, true).value();

        return request;
    }

    std::vector<UsersV1ProfileRequest::Network> ParseNetworks(const drogon::orm::Result& result) {
        std::vector<UsersV1ProfileRequest::Network> networks;
        for (const drogon::orm::Row& row : result) {
            UsersV1ProfileRequest::Network network;
            network.network = row["name"].as<std::string>();
            network.url = row["url"].as<std::string>();
            networks.push_back(network);
        }

        return networks;
    }

    Json::Value Serialize(const UsersV1ProfileRequest& data) {
        Json::Value json;
        json["id"] = data.id;
        json["username"] = data.username;
        json["email"] = data.email;
        Json::Value json_networks(Json::arrayValue);
        for (const auto& network : data.networks) {
            Json::Value json_network;
            json_network["network"] = network.network;
            json_network["url"] = network.url;
            json_networks.append(json_network);
        }
        json["networks"] = json_networks;

        return json;
    }

    UsersV1SocialNetworksRequest ParseSocialNetworksRequest(const Json::Value& json) {
        UsersV1SocialNetworksRequest request;
        request.user_id = NetCardID::utils::extractor::ExtractValueFromJson(json, NetCardID::utils::consts::kUserIdField, true).value();

        std::vector<Json::Value> networks = NetCardID::utils::extractor::ExtractArrayOfJsonsFromJson(json, NetCardID::utils::consts::kNetworksCollectionField, true).value();

        for (const auto& network : networks) {
            UsersV1SocialNetworksRequest::Network net;
            net.network = NetCardID::utils::extractor::ExtractValueFromJson(network, NetCardID::utils::consts::kNetworkNameField, true).value();
            net.url = NetCardID::utils::extractor::ExtractValueFromJson(network, NetCardID::utils::consts::kNetworkUrlField, true).value();
            request.networks.push_back(net);
        }

        return request;
    }
}