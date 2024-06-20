cmake_minimum_required(VERSION 3.5.0)
project(SnakeGame VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
  Sources/main.cpp
  Sources/StateMachine.cpp
)

find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)

add_executable(SnakeGame ${SOURCES})

target_include_directories(SnakeGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Headers)
target_link_libraries(SnakeGame sfml-graphics sfml-audio)
