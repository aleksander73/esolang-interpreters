cmake_minimum_required(VERSION 3.29.2)
project(esolang-interpreters)

set(CMAKE_CXX_STANDARD 20)
set(SRC_FILES "")

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(esolang-interpreters
    ${SRC_FILES}
)

target_include_directories(esolang-interpreters PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/interpreters"
)
