cmake_minimum_required(VERSION 3.25.1)
project(Balagan VERSION 0.0.1)


add_subdirectory(External/SDL)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_DEBUG_POSTFIX d)

# externals do not get the compile options, the hope 
# being that they are reasonable. I'm not going to silence
# warnings for me based on them

if (MSVC)
    add_compile_options(/W4 /WX /Wall)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror -Wconversion)
endif()



add_subdirectory(Src/FileIo)

add_library(Balagan Src/main.cpp)
set_target_properties(Balagan PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

set(BALAGAN_INCLUDES Src/Core Src/Containers Src/FileIo)
target_include_directories(Balagan PUBLIC ${BALAGAN_INCLUDES})
#target_include_directories(Balagan PUBLIC Src/Core)
#target_include_directories(Balagan PUBLIC Src/Containers)
#target_include_directories(Balagan PUBLIC Src/FileIo)
target_include_directories(Balagan PRIVATE external/SDL/include)

set(LIBS FileIo)

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
