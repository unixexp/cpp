cmake_minimum_required(VERSION 3.15)
project(JsonDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(JsonApp main.cpp)

target_link_libraries(JsonApp PRIVATE nlohmann_json::nlohmann_json)
