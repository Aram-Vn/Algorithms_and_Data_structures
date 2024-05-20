
cmake_minimum_required(VERSION 3.10)

project(weighted_graph_adj_list_test)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)  


add_executable(weighted_graph_adj_list_test weighted_graph_adj_list_test.cpp)

target_include_directories(weighted_graph_adj_list_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(weighted_graph_adj_list_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

enable_testing()
add_test(NAME weighted_graph_adj_list_test COMMAND weighted_graph_adj_list_test)
target_compile_options(weighted_graph_adj_list_test PRIVATE -Wall)
        