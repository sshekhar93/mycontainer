message("building mycontainer library")
message("source path: ${CMAKE_CURRENT_SOURCE_DIR} | build path: ${CMAKE_BINARY_DIR}")

cmake_minimum_required(VERSION 3.5)
project(mycontainer)

set(TEST_TARGET "test")
set(SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/set.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/trie.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/bst.cpp")

add_library(${PROJECT_NAME} ${SOURCE_FILES})
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/inc/set.hpp)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})

add_executable(${TEST_TARGET} ./test/test.cpp)
target_link_libraries(${TEST_TARGET} GTest::gtest_main ${PROJECT_NAME})
include(GoogleTest)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

install(TARGETS ${TEST_TARGET})