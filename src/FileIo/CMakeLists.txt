add_library(
    FileIo
    FileIo.cpp
)

set(DEPS ../Containers ../Core) 
target_include_directories(FileIo PRIVATE {DEPS})
