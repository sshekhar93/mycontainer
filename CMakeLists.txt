message("building demo_app project")
message("build director: ${CMAKE_CURRENT_BINARY_DIR}")

cmake_minimum_required(VERSION 3.5)
project(mycontainerDemo LANGUAGES CXX)

#gtest dependency
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/mycontainer ${CMAKE_CURRENT_SOURCE_DIR}/lib/mycontainer/build)
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/mycontainer/build )
target_link_libraries(${PROJECT_NAME} mycontainer)
#target_include_directories(${PROJECT_NAME} PUBLIC mycontainer)
#install(TARGETS ${PROJECT_NAME})