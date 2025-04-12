#include <drogon/drogon.h>

#include "db/db_manager.hpp"

#include "handlers/signup.hpp"


int main() {
    drogon::app().loadConfigFile("config.json");
    auto config = drogon::app().getCustomConfig();
    NetCardID::db::DbManager::init(config["db"]);

    drogon::app().registerHandler(
        NetCardID::users::v1::signup::post::Handler::kName,
        &NetCardID::users::v1::signup::post::Handler::RequestHandler,
        { NetCardID::users::v1::signup::post::Handler::kMethod }
    );

    drogon::app().run();
}