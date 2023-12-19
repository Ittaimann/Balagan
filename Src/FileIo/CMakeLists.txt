add_library(
    FileIo
    FileIo.cpp
    xml/XmlParser.cpp
)

target_include_directories(FileIo PRIVATE ../Containers ../Core /xml)
