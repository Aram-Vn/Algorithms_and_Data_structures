cmake_minimum_required(VERSION 3.10)

project(Graph_test)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/headers)  


add_executable(Graph_test Graph_test.cpp)

target_include_directories(Graph_test PRIVATE ${CMAKE_SOURCE_DIR}/headers)
target_link_libraries(Graph_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

enable_testing()
add_test(NAME Graph_test COMMAND Graph_test)
target_compile_options(Graph_test PRIVATE -Wall)
