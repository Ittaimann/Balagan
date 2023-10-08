
cmake_minimum_required(VERSION 3.27.3)

project(Balagan)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/SDL)
add_executable(Balagan src/main.cpp)
target_include_directories(Balagan PUBLIC external/SDL/include)

if(MSVC)
    set_property(DIRECTORY ${PROJECT_ROOT} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(Balagan PRIVATE SDL2::SDL2main)
endif()
target_link_libraries(Balagan PRIVATE SDL2-static)
