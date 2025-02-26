#include <iostream>
#include <drogon/drogon.h>

int main() {
    drogon::app().loadConfigFile("config.json");
    drogon::app().run();
}