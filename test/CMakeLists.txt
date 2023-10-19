cmake_minimum_required(VERSION 3.0)

add_compile_definitions(OA_VERBOSE)

add_subdirectory(".." "offalloc")

project(test)

include_directories(. ..)

set(SOURCE_FILES
    test.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} offalloc)
