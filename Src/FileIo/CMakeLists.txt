add_library(
    FileIo
    FileIo.cpp
    FileIo.h
)

target_include_directories(FileIo PUBLIC ../Containers ../Core)
