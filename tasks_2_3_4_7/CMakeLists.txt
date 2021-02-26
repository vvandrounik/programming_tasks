cmake_minimum_required (VERSION 3.8)

project(tasks_2_3_4_7)

find_package(GTest REQUIRED)

add_executable (tasks_2_3_4_7
    main.cpp
    braces_validation.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    containers
    GTest::GTest
    GTest::Main
)
