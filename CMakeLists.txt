cmake_minimum_required(VERSION 3.15)
project(luatest)
include(CMakePrintHelpers)

find_package(lua 5.4 REQUIRED)


if (WIN32)
    include_directories(src
            contrib/raylib/include
            contrib/lua/include
            contrib/)

    link_directories(contrib/raylib/lib/x86 contrib/lua/lib/x86 contrib/luajit/lib/x86)
    set(LUA_LIBRARIES lua54.lib)
    set(WIN32_LIBRARIES winmm)
    #set(LUA_LIBRARIES lua51.lib)
else ()
    set(LUA_INCLUDE_DIR /usr/local/include)

    include_directories(${LUA_INCLUDE_DIR} src
            contrib/raylib/include
            contrib/lua/include
            contrib/lua/include/lua
            contrib/)

    find_package(raylib 4.2 REQUIRED) # Requires at least version 3.0

#    target_link_libraries(${PROJECT_NAME} winmm)
    #target_link_libraries(${PROJECT_NAME})
endif ()

set(SOL_BUILD_C_MODE SOL_USE_CXX_LUA)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11) # Requires C11 standard

add_executable(luatest src/main.cpp
        src/entity.cpp
        src/util.cpp
        src/art.cpp
#        src/raylib_bindings.cpp
        src/raylib_bindings1.cpp
        )

target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARIES} raylib ${WIN32_LIBRARIES}) #winmm

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()
