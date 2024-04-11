cmake_minimum_required(VERSION 3.10)

project(priority_queue_tests)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/headers)  

add_executable(priority_queue_tests test_heap.cpp)

target_include_directories(priority_queue_tests PRIVATE ${CMAKE_SOURCE_DIR}/headers)

target_link_libraries(priority_queue_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

enable_testing()
add_test(NAME priority_queue_tests COMMAND priority_queue_tests)
target_compile_options(priority_queue_tests PRIVATE -Wall -Werror)