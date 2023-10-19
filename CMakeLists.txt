cmake_minimum_required(VERSION 3.27.3)

project(Balagan VERSION 0.0.1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/SDL)
add_subdirectory(src/Containers)

add_executable(Balagan src/main.cpp)

target_include_directories(Balagan PRIVATE src/Core)
target_include_directories(Balagan PRIVATE src/Containers)
target_include_directories(Balagan PUBLIC external/SDL/include)


set(LIBS Containers)

if(MSVC)
    set_property(DIRECTORY ${PROJECT_ROOT} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(Balagan SDL2::SDL2main ${LIBS})
endif()
target_link_libraries(Balagan
    SDL2-static
    ${LIBS})
