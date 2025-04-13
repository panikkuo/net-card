#pragma once
#include <memory>
#include <Json/json.h>
#include <drogon/drogon.h>
#include <trantor/utils/Logger.h>

#include "utils/errors.hpp"
#include "utils/extractors.hpp"
#include "utils/validators.hpp"
#include "utils/consts.hpp"

#include "db/db_manager.hpp"
#include "db/db_requests.hpp"

#include "models/users_v1.hpp"

#include "base/base_handler.hpp"

namespace NetCardID::users::v1::signup::post {
    class Handler final : public NetCardID::base::BaseHandler {
    public:
        static constexpr std::string_view kName = "users-v1-signup";
        Handler(Json::Value configs) : BaseHandler(configs, kName) {};
        drogon::Task<drogon::HttpResponsePtr> RequestHandler(const drogon::HttpRequestPtr& request);
    };
}