cmake_minimum_required(VERSION 3.15)

project(DynamicArrayManager)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/source/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

option(ENABLE_DEBUG "Bật chế độ DEBUG" OFF)

if(ENABLE_DEBUG)
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DDEBUG)
    message(STATUS: "DEBUG ON")
else()
    message(STATUS: "DEBUG OFF")
endif()


