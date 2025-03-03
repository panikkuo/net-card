cmake_minimum_required(VERSION 3.16)

project(SocialCard VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third-party/drogon)

set(SOURCES
    src/main.cpp
    src/handlers/signup.hpp
    src/handlers/signup.cpp
    src/utils/consts.hpp
    src/utils/errors.hpp
    src/utils/errors.cpp
    src/utils/validators.hpp
    src/utils/validators.cpp
    src/utils/extractors.hpp
    src/utils/extractors.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE drogon)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/logs)
