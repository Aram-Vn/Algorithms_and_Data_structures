cmake_minimum_required(VERSION 3.10)

project(RB_Tree)

# Always define the TESTING_ENABLED preprocessor macro
# add_compile_definitions(TESTING_ENABLED)

add_executable(RB_Tree main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(RB_Tree PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_subdirectory(tests)

target_compile_options(RB_Tree PRIVATE 
    -Wall
    -Wextra
    -Wshadow
    -Wswitch
    -pedantic
    -Wformat=2
    -Wconversion
    -Wnull-dereference
    -Wunused-parameter
    -Wunreachable-code
    -Wimplicit-fallthrough
    
    -Werror
    -Werror=return-type
    -Werror=uninitialized
    -Werror=unused-result
    -Werror=strict-overflow
   
    -fsanitize=address
    -fsanitize=undefined
   
    -fno-omit-frame-pointer
)

target_link_options(RB_Tree PRIVATE 
    -fsanitize=address
    -fsanitize=undefined
)

target_compile_features(RB_Tree PRIVATE cxx_std_20)
