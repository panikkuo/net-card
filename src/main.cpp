#include <drogon/drogon.h>

#include "db/db_manager.hpp"

#include "handlers/signup.hpp"

#include <iostream>


int main() {
    drogon::app().loadConfigFile("config.json");
    Json::Value config = drogon::app().getCustomConfig();

    NetCardID::db::DbManager::init(config["db"]);

    NetCardID::users::v1::signup::post::Handler signupHandler(config["handlers"]);


    drogon::app().registerHandler(
        signupHandler.kPath,
        [&signupHandler](drogon::HttpRequestPtr req) -> drogon::Task<drogon::HttpResponsePtr> {
            co_return co_await signupHandler.RequestHandler(req);
        },
        {signupHandler.kMethod}
    );
    
    std::cout << "Server started" << std::endl;
    drogon::app().addListener("127.0.0.1", 8080);
    drogon::app().run();
}