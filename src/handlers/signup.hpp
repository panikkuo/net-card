#pragma once
#include <memory>
#include <Json/json.h>

#include "utils/errors.hpp"
#include "utils/extractors.hpp"
#include "utils/validators.hpp"
#include "utils/consts.hpp"

#include "db/db_manager.hpp"
#include "db/db_requests.hpp"

#include "users_v1.hpp"

namespace NetCardID::users::v1::signup::post {
    class Handler final {
    public:
        void RequestHandler(const drogon::HttpRequestPtr& request, std::function<void(const drogon::HttpResponsePtr&)>&& callback);
    private:
        const std::shared_ptr<drogon::orm::DbClient> db = getDbClient();
        std::string kName = "users/v1/signup";
        drogon::HttpMethod kMethod = drogon::Get;
    };
}