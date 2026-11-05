cmake_minimum_required(VERSION 4.0)

project(EventBus LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/AsyncEventBus.cpp
)

add_library(${CMAKE_PROJECT_NAME} ${SOURCES})
add_library(Dexode::EventBus ALIAS ${CMAKE_PROJECT_NAME})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)