cmake_minimum_required (VERSION 3.8)

project(task_5_6)

find_package(GTest REQUIRED)

add_executable (task_5_6
    main.cpp
    check_island.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    containers
    GTest::GTest
    GTest::Main
)
