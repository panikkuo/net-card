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
        &NetCardID::users::v1::signup::post::Handler::RequestHandler,
        {signupHandler.kMethod}
    );

    drogon::app().run();
}