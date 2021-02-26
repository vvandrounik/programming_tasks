cmake_minimum_required (VERSION 3.8)

project ("containers")

add_library(containers STATIC
	src/node.c
	src/linked_list.c	
	src/priority_queue.c
	src/stack.c
)

target_include_directories(containers PUBLIC
	inc
)
