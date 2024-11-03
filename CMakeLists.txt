cmake_minimum_required(VERSION 3.29)

project(Flappy-Bird-Reborn
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glm REQUIRED)
find_package(SFML REQUIRED)
find_package(stellar-forge REQUIRED)

add_executable(flappy-bird)

target_link_libraries(flappy-bird PUBLIC stellar-forge::stellar-forge sfml::sfml glm::glm luacpp lua)

target_sources(flappy-bird
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/Background.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/Bird.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/Pipes.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/Score.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/Background.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/Bird.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/Pipes.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/objects/scripts/Score.cpp
)
