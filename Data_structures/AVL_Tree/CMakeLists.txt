cmake_minimum_required(VERSION 3.10)

project(AVL_Tree)

add_executable(AVL_Tree main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

target_include_directories(AVL_Tree PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(AVL_Tree PRIVATE 
    -Wall 
    -Werror 
    -fsanitize=address 
    -fsanitize=undefined
)

target_link_options(AVL_Tree PRIVATE 
    -fsanitize=address 
    -fsanitize=undefined
)

target_compile_features(AVL_Tree PRIVATE cxx_std_20)