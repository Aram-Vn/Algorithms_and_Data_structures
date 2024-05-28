
cmake_minimum_required(VERSION 3.10)

project("weighted_graph_adj_list")
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HDR_FILES "src/*.h")

add_executable("weighted_graph_adj_list" main.cpp  ${SRC_FILES} ${HDR_FILES})
set_property(TARGET weighted_graph_adj_list PROPERTY CXX_STANDARD 20)

target_include_directories("weighted_graph_adj_list" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
include(CTest)
add_subdirectory(tests)

target_compile_options("weighted_graph_adj_list" PRIVATE 
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

target_link_options("weighted_graph_adj_list" PRIVATE 
    -fsanitize=address
    -fsanitize=undefined
)

target_compile_features("weighted_graph_adj_list" PRIVATE cxx_std_20)

# If not Visual Studio generator, copy compile_commands.json
if(NOT CMAKE_GENERATOR MATCHES "Visual Studio")
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
        DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
        COMMENT "Copying compile_commands.json..."
    )

    add_custom_target(copy_compile_commands ALL
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()
        