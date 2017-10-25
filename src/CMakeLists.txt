rock_library(log2video
    SOURCES Converter.cpp
    HEADERS Converter.hpp
    DEPS_PKGCONFIG opencv
                   base-types
                   pocolog_cpp
                   frame_helper)

rock_executable(Log2Video Main.cpp
    DEPS log2video)

