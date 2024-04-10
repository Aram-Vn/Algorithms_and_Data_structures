cmake_minimum_required(VERSION 3.10)

project(heap)

add_executable(heap main.cpp)

target_include_directories(heap PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src )
        
add_subdirectory(tests)
