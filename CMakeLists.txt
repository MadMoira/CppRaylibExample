cmake_minimum_required(VERSION 3.11.0)
project(raylibtest VERSION 0.1.0)

include(CTest)
enable_testing()

include(ExternalProject REQUIRED)
include(FetchContent REQUIRED)

set(BOX2D_BUILD_TESTBED OFF)

# entt
find_package(entt QUIET)
if (NOT entt_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            entt
            GIT_REPOSITORY https://github.com/skypjack/entt.git
            GIT_TAG v3.10.1
    )
    FetchContent_MakeAvailable(entt)
endif()

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 4.0.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# box2d
find_package(box2d QUIET)
if (NOT box2d_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            box2d
            GIT_REPOSITORY https://github.com/erincatto/box2d.git
            GIT_TAG v2.4.1
    )
    FetchContent_MakeAvailable(box2d)
endif()

add_executable(raylibtest main.cpp main.h utils/utils.cpp utils/utils.h)

target_compile_options(${PROJECT_NAME} PRIVATE -lm)
target_link_options(${PROJECT_NAME} PRIVATE -lm)

target_include_directories(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib EnTT::EnTT PRIVATE box2d)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
