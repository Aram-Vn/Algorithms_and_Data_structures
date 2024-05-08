cmake_minimum_required(VERSION 3.10)

project(Graph_app)


file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HDR_FILES "src/*.h")

add_executable(Graph_app main.cpp  ${SRC_FILES} ${HDR_FILES})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(Graph_app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

# add_subdirectory(tests)

target_compile_options(Graph_app PRIVATE 
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

target_link_options(Graph_app PRIVATE 
    -fsanitize=address
    -fsanitize=undefined
)

target_compile_features(Graph_app PRIVATE cxx_std_20)
