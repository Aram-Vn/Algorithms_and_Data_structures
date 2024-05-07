cmake_minimum_required(VERSION 3.10)

project(Binary_Search_Tree)

add_executable(Binary_Search_Tree main.cpp)

target_include_directories(Binary_Search_Tree PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(Binary_Search_Tree PRIVATE 
    -Wall 
    -Werror 
    # -fsanitize=address 
    -fsanitize=undefined
)

target_link_options(Binary_Search_Tree PRIVATE 
    # -fsanitize=address 
    -fsanitize=undefined
)

target_compile_features(Binary_Search_Tree PRIVATE cxx_std_20)