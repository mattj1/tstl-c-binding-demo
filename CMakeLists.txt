cmake_minimum_required(VERSION 3.15)
project(luatest)
include(CMakePrintHelpers)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11) # Requires C11 standard
set(LUA_INCLUDE_DIR /usr/local/include)

include_directories(src ${LUA_INCLUDE_DIR})
find_package(lua 5.4 REQUIRED)
find_package(raylib 4.2 REQUIRED) # Requires at least version 3.0

add_executable(luatest src/main.cpp
        src/entity.cpp
        src/util.cpp)

target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARIES} raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
