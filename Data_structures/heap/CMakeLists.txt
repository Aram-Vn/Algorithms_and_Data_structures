cmake_minimum_required(VERSION 3.10)

project(priority_queue)

add_executable(priority_queue main.cpp)

target_include_directories(priority_queue PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src )
        
add_subdirectory(tests)

target_compile_options(priority_queue PRIVATE 
    -Wall 
    # -Werror 
    -fsanitize=address 
    -fsanitize=undefined
)

target_link_options(priority_queue PRIVATE 
    -fsanitize=address 
    -fsanitize=undefined
)