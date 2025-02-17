cmake_minimum_required(VERSION 3.10)

project(DynamicArrayManger)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/source/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})