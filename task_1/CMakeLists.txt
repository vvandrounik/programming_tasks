cmake_minimum_required (VERSION 3.8)

project(task_1)

find_package(GTest REQUIRED)

add_executable (task_1
    main.cpp
    reverse_bits.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    GTest::GTest
    GTest::Main
)
