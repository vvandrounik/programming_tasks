# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("programming_tasks")

# Include sub-projects.
add_subdirectory ("containers")
add_subdirectory("task_1")
add_subdirectory("tasks_2_3_4_7")
add_subdirectory("tasks_5_6")