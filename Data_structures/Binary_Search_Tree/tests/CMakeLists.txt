cmake_minimum_required(VERSION 3.10)

project(BST_test)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/headers)  

add_executable(BST_test test_heap.cpp)

target_include_directories(BST_test PRIVATE ${CMAKE_SOURCE_DIR}/headers)

target_link_libraries(BST_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

enable_testing()
add_test(NAME BST_test COMMAND BST_test)
target_compile_options(BST_test PRIVATE -Wall)