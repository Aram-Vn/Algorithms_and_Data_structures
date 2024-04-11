cmake_minimum_required(VERSION 3.10)

project(heap_tests)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/headers)  

add_executable(heap_tests test_heap.cpp)

target_include_directories(heap_tests PRIVATE ${CMAKE_SOURCE_DIR}/headers)

target_link_libraries(heap_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

enable_testing()
add_test(NAME heap_tests COMMAND heap_tests)
