#include <drogon/drogon.h>

#include "db/db_manager.hpp"

#include "handlers/signup.hpp"


int main() {
    drogon::app().loadConfigFile("config.json");
    auto config = drogon::app().getCustomConfig();
    NetCardID::db::DbManager::init(config["db"]);

    NetCardID::users::v1::signup::post::Handler signupHandler(config);

    drogon::app().registerHandler(
        signupHandler.kPath,
        [&signupHandler](drogon::HttpRequestPtr req) -> drogon::Task<drogon::HttpResponsePtr> {
            co_return co_await signupHandler.RequestHandler(req);
        },
        {signupHandler.kMethod}
    );

    drogon::app().run();
}