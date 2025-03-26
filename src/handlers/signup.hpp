#pragma once
#include <memory>
#include <Json/json.h>
#include <drogon/drogon.h>

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
        std::string kName = "users/v1/signup";
        drogon::HttpMethod kMethod = drogon::Post;
    private:
        const std::shared_ptr<drogon::orm::DbClient> db = getDbClient();
    };
}