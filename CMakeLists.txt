cmake_minimum_required(VERSION 3.16)

project(NetCard VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third-party/drogon)

find_package(PostgreSQL REQUIRED)


set(SOURCES
    src/main.cpp
    src/objects/objects_v1.hpp
    src/utils/consts.hpp
    src/utils/errors.hpp
    src/utils/errors.cpp
    src/utils/validators.hpp
    src/utils/validators.cpp
    src/utils/extractors.hpp
    src/utils/extractors.cpp
    src/db/db_manager.hpp
    src/db/db_manager.cpp
    src/db/db_requests.hpp
    src/models/users_v1.hpp
    src/models/users_v1.cpp
    src/handlers/signup.hpp
    src/handlers/signup.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    drogon 
    PostgreSQL::PostgreSQL
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
    ${PostgreSQL_INCLUDE_DIR} 
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/logs)