cmake_minimum_required(VERSION 4.0)

project(EventBus LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(EventBus sources/AsyncEventBus.cpp)
add_library(Dexode::EventBus ALIAS EventBus)

target_include_directories(EventBus PUBLIC include)