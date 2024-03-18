add_library(
    Window
    Window.cpp
)

target_include_directories(Window PRIVATE ../../Containers ../../Core ../../../External/SDL/include .)
target_link_libraries( Window SDL2-static )
