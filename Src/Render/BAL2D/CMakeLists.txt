add_library(
    BAL2D
    BAL2D.cpp
)

target_include_directories(BAL2D PRIVATE ../../Containers ../../Core ../../Os/Window ../../External/SDL/include .)
target_link_libraries( BAL2D Window SDL2-static )
