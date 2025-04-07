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

#include "models/users_v1.hpp"

namespace NetCardID::users::v1::signup::post {
    class Handler final {
    public:
        drogon::Task<drogon::HttpResponsePtr> RequestHandler(const drogon::HttpRequestPtr& request);
        std::string kName = "/api/users/v1/signup";
        const static drogon::HttpMethod kMethod = drogon::Post;
    private:
        const static std::shared_ptr<drogon::orm::DbClient> db = getDbClient();
    };
}