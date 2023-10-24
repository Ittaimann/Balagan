cmake_minimum_required(VERSION 3.25.1)
project(Balagan VERSION 0.0.1)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory(external/SDL)
add_subdirectory(src/Containers)


if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(Balagan src/main.cpp)
set_target_properties(Balagan PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_include_directories(Balagan PRIVATE src/Core)
target_include_directories(Balagan PRIVATE src/Containers)
target_include_directories(Balagan PUBLIC external/SDL/include)

set(LIBS Containers)

if (MSVC)
    set_property(DIRECTORY ${PROJECT_ROOT} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    #    target_link_libraries(Balagan PRIVATE SDL2::SDL2main ${LIBS})
    #else()
endif()

target_link_libraries(Balagan
    SDL2-static
    ${LIBS})
