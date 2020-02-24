cmake_minimum_required(VERSION 3.13)
project(LexI)

set(CMAKE_CXX_STANDARD 14)

# interface lib
add_library(lexi_interface INTERFACE)
target_include_directories(lexi_interface INTERFACE inc)

set(PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/src)

FILE(GLOB MY_SOURCES ${PROJECT_SOURCES}/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${MY_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE lexi_interface)


# Platform dependent stuff
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_subdirectory(src/lexi_linux)

    target_link_libraries(${PROJECT_NAME} PRIVATE lexi_linux)
else ()
    message(FATAL "Unsupported System")
endif ()