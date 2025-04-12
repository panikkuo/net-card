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

namespace NetCardID::users::v1::signup::post {
    class Handler final {
    public:
        static drogon::Task<drogon::HttpResponsePtr> RequestHandler(const drogon::HttpRequestPtr& request);
        const static std::string kName = "/api/v1/users/signup";
        const static drogon::HttpMethod kMethod = drogon::Post;
    private:
        const static std::shared_ptr<drogon::orm::DbClient> db = db::DbManager::getDbClient();
    };
}