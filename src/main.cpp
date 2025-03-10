#include <iostream>
#include <drogon/drogon.h>

int main() {
    drogon::app().loadConfigFile("config.json");
    auto config = drogon::app().getCustomConfig();
    //DbManager::init(config["db"]);
    drogon::app().run();
}