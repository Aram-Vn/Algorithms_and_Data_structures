cmake_minimum_required(VERSION 3.10)

project(RB_Tree_test)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/headers)  

add_definitions(-DTESTING_ENABLED)

add_executable(RB_Tree_test RB_Tree_test.cpp)

target_include_directories(RB_Tree_test PRIVATE ${CMAKE_SOURCE_DIR}/headers)
target_link_libraries(RB_Tree_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

enable_testing()
add_test(NAME RB_Tree_test COMMAND RB_Tree_test)
target_compile_options(RB_Tree_test PRIVATE -Wall)
