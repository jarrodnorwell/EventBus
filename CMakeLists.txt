cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(EventBus LANGUAGES CXX)

add_library(EventBus sources/AsyncEventBus.cpp)
add_library(Dexode::EventBus ALIAS EventBus)

if (MSVC)
    target_compile_features(EventBus PRIVATE cxx_std_23)
    target_compile_options(EventBus PRIVATE /std:c++latest)
endif()

target_include_directories(EventBus
    PRIVATE include/eventbus/internals
    PRIVATE include/eventbus/utilities
    PUBLIC include
)